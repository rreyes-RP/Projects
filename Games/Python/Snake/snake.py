from constants import GRID_WIDTH, GRID_HEIGHT

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