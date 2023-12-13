/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:32 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/13 14:42:40 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Required functionality:
 * 1) Read map in format *.ber
 * 2) Open window
 * 3) draw map on screen
 * 4) Draw sprite
 * 5) Handle movement and apply animation as required
 * 		a) prevent movement into walls
 * 6) track moves
 * 7) Ensure ESC closes the window and quits cleanly
 * 8) Ensure close window button closes and quits cleanly
 * 9) Obtain sprites for: 
 * 		a) empty space
 * 		b) walls
 * 		c) collectible
 * 		d) for map exit
 * 		e) for player starting position
 * 10) proper map validation to ensure that there is exactly one exit, one
 * 		starting position and at least one collectible. else display error 
 * 		message.
 * 			a) also needs to enforce a rectangular map
 * 			b) must have walls along the edges
 * 			c) there must be a valid path
 * 	Bonus:
 *
 * 	1) make the player lose if they touch an enemy patrol
 * 		a) find sprites for enemies
 * 		b) create patrol pathing
 * 	2) add some sprite animation
 * 	3) display the movement count directly on screen, not just on the shell
