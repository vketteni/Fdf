/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:24:46 by vketteni          #+#    #+#             */
/*   Updated: 2024/02/13 14:57:45 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_fdf_parser	*initialize_parser(void)
{
	t_fdf_parser	*parser;

	parser = (t_fdf_parser *)malloc(sizeof(t_fdf_parser));
	if (parser == NULL)
		return (NULL);
	parser->v_pos = 0;
	parser->h_pos = 0;
	parser->fdf_fd = -1;
	parser->line = NULL;
	parser->row = NULL;
	return (parser);
}

static int	parse_line(t_fdf_parser *parser, t_param *param)
{
	t_coordinate	*coordinate;

	parser->row = ft_split(parser->line, ' ');
	if (parser->row == NULL)
	{
		free_strarr(parser->row);
		return (-1);
	}
	while ((parser->row)[parser->h_pos]
		&& *(parser->row)[parser->h_pos] != '\n')
	{
		coordinate = create_coordinate(parser->h_pos, parser->v_pos,
				ft_atoi(parser->row[parser->h_pos]));
		if (coordinate == NULL)
		{
			free_strarr(parser->row);
			return (-1);
		}
		param->all_coordinates[parser->v_pos][parser->h_pos] = coordinate;
		parser->h_pos++;
	}
	free_strarr(parser->row);
	parser->v_pos++;
	parser->h_pos = 0;
	return (0);
}

int	fdf_parse(char *fdf_file, t_param *param)
{
	t_fdf_parser	*parser;

	parser = initialize_parser();
	if (!parser)
		return (-1);
	parser->fdf_fd = open(fdf_file, O_RDONLY);
	if (parser->fdf_fd < 0)
		return (-1);
	parser->line = get_next_line(parser->fdf_fd, RESET_BUFFER);
	while (parser->line != NULL)
	{
		if (parse_line(parser, param) == -1)
		{
			close(parser->fdf_fd);
			free(parser->line);
			free(parser);
			return (-1);
		}
		free(parser->line);
		parser->line = get_next_line(parser->fdf_fd, DEFAULT);
	}
	close(parser->fdf_fd);
	free(parser);
	return (0);
}
