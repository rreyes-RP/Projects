import numpy as np
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Flatten

# Load the dataset
with np.load('/Users/roriereyes/Documents/Projects/AI_Projects/mnist.npz') as data:
    x_train, y_train = data['x_train'], data['y_train']
    x_test, y_test = data['x_test'], data['y_test']

# Normalize pixel values to be between 0 and 1
x_train = x_train / 255.0
x_test = x_test / 255.0

# Build the neural network model
model = Sequential([
    Flatten(input_shape=(28, 28)),        # Flatten the 2D image to 1D array
    Dense(128, activation='relu'),       # Fully connected layer with ReLU activation
    Dense(10, activation='softmax')      # Output layer with softmax activation for classification
])

# Compile the model
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

# Train the model
model.fit(x_train, y_train, epochs=5, validation_data=(x_test, y_test))

# Evaluate the model
test_loss, test_acc = model.evaluate(x_test, y_test, verbose=2)
print(f"\nTest accuracy: {test_acc*100:.2f}%")

# Make predictions
predictions = model.predict(x_test)

# Print some actual and predicted labels
import random

for _ in range(5):
    i = random.randint(0, len(x_test))
    print(f"Actual: {y_test[i]}, Predicted: {np.argmax(predictions[i])}")
