import random
import pygame
from constants import GRID_WIDTH, GRID_HEIGHT, GRID_SIZE, WINDOW_SIZE, WHITE, GREEN, RED

class Food:
    def __init__(self):
        self.position = (random.randint(0, GRID_WIDTH - 1), random.randint(0, GRID_HEIGHT - 1))
        
    def draw(self):
        pygame.draw.rect(WINDOW, RED, (self.position[0] * GRID_SIZE, self.position[1] * GRID_SIZE, GRID_SIZE, GRID_SIZE))
        