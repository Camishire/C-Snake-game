This game was developed for a university project.

Project Requirements :
The main requirement was to utilize C++ object-oriented programming (OOP) principles extensively. Therefore, several OOP features have been incorporated to demonstrate understanding, such as:
- Class Hierarchies: There are three classes: base, game, and snake. The game and snake classes both inherit from the base class, demonstrating inheritance and reuse of base functionality.
- Constructors and Destructors: Each class uses constructors and destructors to manage resources such as vectors and maps effectively.
- Operator Overloading: The assignment operator = is overloaded in the base class to handle player name initialization, adding a customized touch to the game setup process.
- Encapsulation: Variables like SL (Snake Length), name, and ST (Snake Type) are protected members of the base class, ensuring their values can only be accessed and modified through controlled methods, thus preserving encapsulation.
- Polymorphism: The game involves polymorphism with function overloading, particularly through different class methods such as key_entry(), setST(), and game_running(), which allow specialized functionality for the derived classes.

Game Description :
This is a classic Snake game implemented in C++. The objective is to move a snake around the arena, collect food, and grow longer while avoiding collisions with the arena borders or the snake's own body.

Visual game elements :
- Graphics: The game is text-based and uses a 2D array (arena) to represent the game board. The snake and food items are rendered as characters on the console.
- Movement: Player movement is controlled through arrow keys using GetAsyncKeyState() to detect keypresses, which allows for real-time input handling.
- Random Food Placement: The randomiser() method places food at random empty locations on the board. It uses the rand() function and a vector to manage food placement.
- Snake Customization: Players can select their preferred snake symbol from a list of characters using the arrow keys, which adds a bit of personalization to the game.

Classes Overview :
- Base Class (base): Handles core functionality, such as setting up the game arena, storing player data, and rendering the board. It manages common attributes and methods that are shared between game components, including the snake's position, length, and score management.
- Game Class (game): Inherits from base and manages the core gameplay loop, such as taking player input, updating the snake's movement, and tracking collisions with food or obstacles.
- Snake Class (snake): Handles options related to snake customization, such as choosing the snake's appearance. It uses a set to store available snake symbols and allows the player to select their desired symbol for the snake's body.


Controls :
- Arrow Keys: Control the movement of the snake.
- Space: Confirm snake symbol selection during customization.
- Enter: Confirm your name selection

This project demonstrates the application of object-oriented programming in a fun and interactive way. Feel free to explore the code, make improvements, or adapt it for other uses!

