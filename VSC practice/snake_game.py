import pygame
import time
import random

snake_speed = 10

# Window size
window_x = 720
window_y = 480

# Colors
black = pygame.Color(0, 0, 0)
white = pygame.Color(255, 255, 255)
red = pygame.Color(255, 0, 0)
green = pygame.Color(0, 255, 0)
blue = pygame.Color(0, 0, 255)

pygame.init()

# Initialise game window
pygame.display.set_caption('Snake Game')
game_window = pygame.display.set_mode((window_x, window_y))

# FPS controller
fps_controller = pygame.time.Clock()

# Snake position
snake_position = [100, 50]

# First four blocks of snake
# Each block is [x, y]
# e.g. [[100, 50], [90, 50], [80, 50], [70, 50]]
snake_body = [[100, 50], [90, 50], [80, 50], [70, 50]]

# Food position
food_position = [random.randrange(1, (window_x//10)) * 10,
                 random.randrange(1, (window_y//10)) * 10]
food_spawn = True

# Default snake direction
# Right
direction = 'RIGHT'
change_to = direction

# Score
score = 0

# Game Over
def game_over():
    font = pygame.font.SysFont('Arial', 30)
    text = font.render('Game Over! Your score is: ' + str(score), True, red)
    game_window.blit(text, (window_x/3, window_y/3))
    pygame.display.flip()
    time.sleep(3)
    pygame.quit()
    quit()

# Main game loop
def gameLoop():
    global direction, change_to, snake_position, food_position, food_spawn, score

    game_over = False
    while not game_over:
        # Check for QUIT event
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True

            # Change the direction of the snake
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    change_to = 'UP'
                if event.key == pygame.K_DOWN:
                    change_to = 'DOWN'
                if event.key == pygame.K_LEFT:
                    change_to = 'LEFT'
                if event.key == pygame.K_RIGHT:
                    change_to = 'RIGHT'

        # Do not allow the snake to move in the opposite direction instantly
        if change_to == 'UP' and direction != 'DOWN':
            direction = 'UP'
        if change_to == 'DOWN' and direction != 'UP':
            direction = 'DOWN'
        if change_to == 'LEFT' and direction != 'RIGHT':
            direction = 'LEFT'
        if change_to == 'RIGHT' and direction != 'LEFT':
            direction = 'RIGHT'

        # Move the snake
        if direction == 'UP':
            snake_position[1] -= 10
        if direction == 'DOWN':
            snake_position[1] += 10
        if direction == 'LEFT':
            snake_position[0] -= 10
        if direction == 'RIGHT':
            snake_position[0] += 10

        # Snake body growing mechanism
        # If the food is eaten
        # The block is added to the snake body
        snake_body.insert(0, list(snake_position))
                # If snake eats the food
        if snake_position == food_position:
            food_spawn = False
            score += 10
             # Increase length of snake
            snake_body.append([snake_position[0], snake_position[1]])

        # Spawn food at a new location
        if not food_spawn:
            food_position = [random.randrange(1, (window_x//10)) * 10,
                             random.randrange(1, (window_y//10)) * 10]
        food_spawn = True
       for  score += 10 in score:
        snake_speed += 10
        # Length of snake
        # Remove the last block of the snake
        # If the length of the snake is greater than the score
        if len(snake_body) > score/10:
            del snake_body[-1]

        # Check if the snake hits the boundaries
        if snake_position[0] < 0 or snake_position[0] > window_x-10:
            game_over()
        if snake_position[1] < 0 or snake_position[1] > window_y-10:
            game_over()

        # Check if the snake hits itself
        for block in snake_body[1:]:
            if snake_position == block:
                game_over()

        # Fill the background color
        game_window.fill(black)

        # Draw the snake
        for block in snake_body:
            pygame.draw.rect(game_window, green, pygame.Rect(
                block[0], block[1], 10, 10))

        # Draw the food
        pygame.draw.rect(game_window, white, pygame.Rect(
            food_position[0], food_position[1], 10, 10))

        # Update the score
        font = pygame.font.SysFont('Arial', 20)
        score_text = font.render('Score: ' + str(score), True, blue)
        game_window.blit(score_text, (5, 5))

        # Update the display
        pygame.display.update()

        # FPS controller
        fps_controller.tick(snake_speed)

# Start the game loop
gameLoop()

# Quit pygame and the program
pygame.quit()
quit()
