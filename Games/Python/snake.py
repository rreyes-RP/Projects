import pygame
import random

# Initialize pygame
pygame.init

# Set up display
WINDOW_SIZE = 500
GRID_SIZE = 20
GRID_WIDTH = WINDOW_SIZE // GRID_SIZE
GRID_HEIGHT = WINDOW_SIZE // GRID_SIZE
WINDOW = pygame.display.set_mode((WINDOW_SIZE, WINDOW_SIZE))
pygame.display.set_caption('RP Studio - Snake Game')

# Colors
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

class Snake:
    def __init__(self):
        self.body = [(GRID_WIDTH // 2, GRID_HEIGHT // 2)]
        self.direction = (1,0)
        self.grow = False
        
    def move(self):
        head = self.body[-1]
        new_head = (head[0] + self.direction[0], head[1] + self.direction[1])
        
        if new_head == food.position:
            self.grow = True
            
        self.body.append(new_head)
        
        if not self.grow:
            self.body.pop(0)
        else:
            self.grow = False
        
    def draw(self):
        for segment in self.body:
            pygame.draw.rect(WINDOW, GREEN, (segment[0] * GRID_SIZE, segment[1] * GRID_SIZE, GRID_SIZE, GRID_SIZE))
        
    def check_collision(self):
        head = self.body[-1]
        return head in self.body[:-1] or head[0] < 0 or head[0] >= GRID_WIDTH or head[1] >= GRID_HEIGHT
    
    def change_direction(self, new_direction):
        if (new_direction[0] * -1, new_direction[1] * -1) != self.direction:
            self.direction = new_direction

class Food:
    def __init__(self):
        self.position = (random.randint(0, GRID_WIDTH - 1), random.randint(0, GRID_HEIGHT - 1))
        
    def draw(self):
        pygame.draw.rect(WINDOW, RED, (self.position[0] * GRID_SIZE, self.position[1] * GRID_SIZE, GRID_SIZE, GRID_SIZE))
        
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
    

            