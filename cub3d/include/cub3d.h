/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:28:00 by nakoriko          #+#    #+#             */
/*   Updated: 2025/07/17 15:01:06 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define W 119
# define A 97
# define S 115
# define D 100

# define LEFT 65361
# define RIGHT 65363

# define MOVE_SPEED 0.52
# define ROT_SPEED 0.07

# define SCREEN_WIDTH	1280
# define SCREEN_HEIGHT	960
# define TEXTURE_SIZE	64

# define NORTH_TXTR	0
# define SOUTH_TXTR	1
# define WEST_TXTR	2
# define EAST_TXTR	3

/* ------------------------------------------------------------------------- */
/*                                 STRUCTURES                                */
/* ------------------------------------------------------------------------- */

/* -------------- struttura per tenere file di configuarazione ------------- */

typedef struct s_config
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_color;
	int		ceiling_color;
	int		no_dup;
	int		so_dup;
	int		we_dup;
	int		ea_dup;
	int		floor_dup;
	int		ceiling_dup;
}	t_config;

/* ---------- struttura per tenere le informazioni della mappa .cub -------- */
typedef struct s_map
{
	char	**map_mtx;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	player_dir;
	int		player_dup;
}	t_map;

/* ---------- struttura per tenere le informazioni dell'immagine ----------- */
// Forse non serve, ma lo metto per ora
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

/* ----------- struttura per tenere le informazioni delle texture ---------- */
typedef struct s_wall
{
	void	*ptr;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		size_line;
	int		endian;
}	t_wall;

/* ------------ Struttura per il player (posizione e direzione) ------------ */
typedef struct s_player
{
	double	pos_x;		// Posizione X del player (coordinate precise)
	double	pos_y;		// Posizione Y del player (coordinate precise)
	double	dir_x;		// Direzione X del vettore direzione
	double	dir_y;		// Direzione Y del vettore direzione
	double	plane_x;	// Piano della camera X (per FOV)
	double	plane_y;	// Piano della camera Y (per FOV)
	double	move_speed;	// Velocità di movimento
	double	rot_speed;	// Velocità di rotazione
}	t_player;

/* ------------------ Struttura per il raycasting ------------------ */
typedef struct s_ray
{
	double	camera_x;		// Coordinata X sulla camera (-1 a 1)
	double	ray_dir_x;		// Direzione X del raggio
	double	ray_dir_y;		// Direzione Y del raggio
	int		map_x;			// Coordinata X sulla mappa (int)
	int		map_y;			// Coordinata Y sulla mappa (int)
	double	side_dist_x;	// Distanza al prossimo lato X
	double	side_dist_y;	// Distanza al prossimo lato Y
	double	delta_dist_x;	// Distanza tra lati X
	double	delta_dist_y;	// Distanza tra lati Y
	double	wall_dist;		// Distanza perpendicolare al muro
	int		step_x;			// Direzione del passo X (-1 o 1)
	int		step_y;			// Direzione del passo Y (-1 o 1)
	int		hit;			// Se il raggio ha colpito un muro
	int		side;			// Che lato del muro è stato colpito (0=NS, 1=EW)
	int		line_height;	// Altezza della linea da disegnare
	int		draw_start;		// Pixel di inizio disegno
	int		draw_end;		// Pixel di fine disegno
}	t_ray;

/* ------------------ Struttura per le texture ------------------ */
typedef struct s_texture
{
	int		tex_num;		// Numero della texture (0=NO, 1=SO, 2=WE, 3=EA)
	double	wall_x;			// Punto esatto dove il muro è stato colpito
	int		tex_x;			// Coordinata X sulla texture
	int		tex_y;			// Coordinata Y sulla texture
	double	step;			// Quanto aumentare tex_y per ogni pixel
	double	tex_pos;		// Posizione attuale sulla texture
}	t_texture;

/* ------------- struttura per tenere le informazioni di gioco ------------- */
typedef struct s_game
{
	t_config	config;
	t_map		map;
	t_img		img;
	t_wall		wall[4];
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	//aggiungere il player ed altri strutture di ENGINE qui
	t_player	player;
	t_ray		ray;
	t_texture	texture;
}	t_game;

/* ------------------------------------------------------------------------- */
/*                                   PARSER                                  */
/* ------------------------------------------------------------------------- */

/* ------------------------------ parser main.c ---------------------------- */
// lettura e check di config file ed i suoi componenti
int		ft_file_parser(t_game *game, const char *file);
int		ft_scroll_line(char **line, int fd, t_game *game, int res);
int		ft_check_file(t_game *game, char **line, int fd);
int		check_config(t_config *config);
int		texture_is_valid(char *path);

/* -------------------------- parser_texture_line.c ------------------------- */
//Controlla e salva le informazioni delle texture e dei colori
//nella struttura config
int		ft_parsing_texture_line(t_config *config, char *line);
int		color_check(int *color, int *dup, char *line, int i);
int		rgb_parser(char *line, int *i);
int		texture_check(char **texture_path, int *dup, char *line, int i);
int		ft_istexture_line(char *line);

/* ----------------------------- parser_map.c ------------------------------- */
// Alloca la memoria per la matrice della mappa e salva le informazioni
// dentro la struttura map
// Chiama validazione della mappa
int		ft_parsing_map(t_game *game, int fd, char **line);
int		ft_check_map_line(char *str);
int		ft_check_max_lenght(int size, char **mtx);
void	free_map(char **mtx, int size);

/* ---------------------------- map_validation.c --------------------------- */
int		map_validation(t_game *game);
int		ft_check_chars_inside(t_map *map, int i, int len, int j);
int		empty_line_inside(char **mtx, int height);
int		player_pos_check(t_map *map, int i, int j);

/* -------------------------- unclosed_map_check.c ------------------------- */
// Controlla se la mappa è chiusa (tutte le celle sono circondate da muri)
int		map_is_closed(t_map map);
int		ft_check_around(char **mtx, int y, int x, int height);
int		ft_safe_zone(char **mtx, int y, int x, int height);

/* ------------------------------------------------------------------------- */
/*                                    INIT                                   */
/* ------------------------------------------------------------------------- */

/* ------------------------------- init_game.c ----------------------------- */
int		ft_init(t_game *game);
int		init_player(t_game *game);
void	set_player_dir(t_game *game, char dir);
void	set_camera_plane(t_game *game);

/* ----------------------------- init_textures.c --------------------------- */
int		init_image(t_game *game, int width, int height);
int		load_xpm(t_game *game, int i, char *path);
int		ft_init_textures(t_game *game);

/* ------------------------------------------------------------------------- */
/*                                   EVENTS                                  */
/* ------------------------------------------------------------------------- */

/* --------------------------------- hooks.c ------------------------------- */
// gestione degli eventi della tastiera
int		handle_exit(t_game *game);
int		handle_key(int keycode, t_game *game);

/* ------------------------------- movements.c ----------------------------- */
void	forward_move(t_game *game);
void	backward_move(t_game *game);
void	left_move(t_game *game);
void	right_move(t_game *game);
void	left_rotate(t_game *game);
void	right_rotate(t_game *game);
int		is_position_safe(t_game *game, double x, double y, double margin);

/* ------------------------------------------------------------------------- */
/*                                   ENGINE                                  */
/* ------------------------------------------------------------------------- */

/* ----------------------------- raycasting.c ---------------------------- */
void	calculate_ray(t_game *game, int x);
void	setup_dda(t_game *game);
void	reset_ray(t_game *game);
void	perform_dda(t_game *game);
void	calculate_wall_distance(t_game *game);
void	calculate_wall_height(t_game *game);
void	normalize_vectors(t_game *game);

/* ----------------------------- redraw_render.c --------------------------- */
// redisegna l'immagine nella finestra
// Chiamata di render generale !!!!!!! ENGINE !!!!!!!!
void	render_scene(t_game *game);
int		ft_rerender(t_game *game);
void	ft_floor_celling_render(t_game *game);
void	raycasting(t_game *game);
void	calculate_texture_coordinates(t_game *game);
void	draw_textured_wall(t_game *game, int x);

/* ------------------------------------------------------------------------- */
/*                                    UTILS                                  */
/* ------------------------------------------------------------------------- */

/* ------------------------------- free_all.c ------------------------------ */
void	ft_pre_exit(t_game *game); // pulizia di tutto-tutto prima di uscire
void	free_all(t_game *game); // libera tutte le strutture allocate
void	free_t_map(char **mtx, int size);
void	free_t_config(t_config *cf);

/* ------------------------------- utils.c --------------------------------- */
void	trim_line(char *str);
int		ft_isempty_line(char *str);
void	ft_free_close(char *line, int fd); // free and close
void	ft_free_null(char *line);

//serve per controllare che non ci sono trash dopo colore dentro configline
int		check_rest_of_the_line(char *line, int i);

/* ------------------------------- errors.c -------------------------------- */
int		ft_error(char *str); // stampa l'errore e ritorna 1

/* -------------------------------- utils_raycasting.c --------------------- */
void	calculate_delta_x_y(t_game *game);
void	calculate_side_dist_x(t_game *game);

/* ----------------------------- utils_redraw_render.c --------------------- */
void	checks_wall(t_texture *texture);
int		get_texture_color(t_game *game, int tex_num, int tex_x, int tex_y);
void	design_pixel(int x, int y, int color, t_game *game);
int		determine_wall_texture(t_game *game);
#endif
