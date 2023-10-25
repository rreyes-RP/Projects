import pygame
from snake import Snake
from food import Food
from constants import GRID_WIDTH, GRID_HEIGHT, WINDOW_SIZE, WHITE, GREEN, RED

# Initialize pygame
pygame.init

# Set up display
WINDOW = pygame.display.set_mode((WINDOW_SIZE, WINDOW_SIZE))
pygame.display.set_caption('RP Studio - Snake Game')

# Initialize game objects
snake = Snake()
food = Food()

# Game Loop
clock = pygame.time.Clock()
game_over = False

while not game_over:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game_over = True
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                snake.change_direction((0, -1))
            elif event.key == pygame.K_DOWN:
                snake.change_direction((0, 1))
            elif event.key == pygame.K_LEFT:
                snake.change_direction((-1, 0))
            elif event.key == pygame.K_RIGHT:
                snake.change_direction((1, 0))

    snake.move()

    if snake.check_collision():
        game_over = True

    if snake.body[-1] == food.position:
        food = Food()
        
    WINDOW.fill(WHITE)
    snake.draw()
    food.draw()
    pygame.display.update()
    clock.tick(10)

pygame.quit()