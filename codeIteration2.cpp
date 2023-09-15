#include <bits/stdc++.h>

using namespace std;

// Define a structure to represent a 3D position
struct Position
{
    int x, y, z;
};

// Define an enumeration to represent directions
enum Direction
{
    N,
    S,
    E,
    W,
    Up,
    Down
};

// Function to convert Direction enum to corresponding character
char directionToChar(Direction dir)
{
    switch (dir)
    {
    case N:
        return 'N';
    case S:
        return 'S';
    case E:
        return 'E';
    case W:
        return 'W';
    case Up:
        return 'U';
    case Down:
        return 'D';
    default:
        return 'N'; // Default to North
    }
}

// Define a class to represent a spacecraft
class Chandrayaan3
{
private:
    Position position;
    Direction direction;
    Direction prevDir;

public:
    // Constructor to initialize the spacecraft's position and direction
    Chandrayaan3(int x, int y, int z, Direction dir)
    {
        position.x = x;
        position.y = y;
        position.z = z;
        direction = dir;
    }

    // Function to move the spacecraft based on a given command
    void move(char command)
    {
        switch (command)
        {
        case 'f':
            moveForward();
            break;
        case 'b':
            moveBackward();
            break;
        case 'l':
            turnLeft();
            break;
        case 'r':
            turnRight();
            break;
        case 'u':
            turnUp();
            break;
        case 'd':
            turnDown();
            break;
        }
    }

    // Functions to move the spacecraft in different directions
    void moveForward()
    {
        switch (direction)
        {
        case N:
            position.y++;
            break;
        case S:
            position.y--;
            break;
        case E:
            position.x++;
            break;
        case W:
            position.x--;
            break;
        case Up:
            position.z++;
            break;
        case Down:
            position.z--;
            break;
        }
    }

    void moveBackward()
    {
        switch (direction)
        {
        case N:
            position.y--;
            break;
        case S:
            position.y++;
            break;
        case E:
            position.x--;
            break;
        case W:
            position.x++;
            break;
        case Up:
            position.z--;
            break;
        case Down:
            position.z++;
            break;
        }
    }

    void turnLeft()
    {
        switch (direction)
        {
        case N:
            direction = W;
            break;
        case S:
            direction = E;
            break;
        case E:
            direction = N;
            break;
        case W:
            direction = S;
            break;
        case Up:
            if (directionToChar(prevDir) == 'E')
                direction = N;
            else if (directionToChar(prevDir) == 'W')
                direction = S;
            else if (directionToChar(prevDir) == 'N')
                direction = W;
            else
                direction = E;
        case Down:
            if (directionToChar(prevDir) == 'E')
                direction = N;
            else if (directionToChar(prevDir) == 'W')
                direction = S;
            else if (directionToChar(prevDir) == 'N')
                direction = W;
            else
                direction = E;
        }
    }

    void turnRight()
    {
        switch (direction)
        {
        case N:
            direction = E;
            break;
        case S:
            direction = W;
            break;
        case E:
            direction = S;
            break;
        case W:
            direction = N;
            break;
        case Up:
            if (directionToChar(prevDir) == 'E')
                direction = S;
            else if (directionToChar(prevDir) == 'W')
                direction = N;
            else if (directionToChar(prevDir) == 'N')
                direction = E;
            else
                direction = W;
        case Down:
            if (directionToChar(prevDir) == 'E')
                direction = S;
            else if (directionToChar(prevDir) == 'W')
                direction = N;
            else if (directionToChar(prevDir) == 'N')
                direction = E;
            else
                direction = W;
        }
    }

    void
    turnUp()
    {
        if (direction != Up)
        {
            prevDir = direction;
            direction = Up;
        }
    }

    void turnDown()
    {
        if (direction != Down)
        {
            prevDir = direction;
            direction = Down;
        }
    }

    // Function to get the current position
    Position getPosition()
    {
        return position;
    }

    // Function to get the current direction
    Direction getDirection()
    {
        return direction;
    }
};

// Function to perform test cases
void runTests()
{
    int x = 0, y = 0, z = 0;
    Direction initialDirection = N;
    Chandrayaan3 spacecraft(x, y, z, initialDirection);

    // Test move
    spacecraft.moveForward();
    Position pos = spacecraft.getPosition();

    if (pos.x == 0 && pos.y == 1 && pos.z == 0)
        cout << "Move test passed\n";
    else
        cout << "Move test failed\n";

    // Test turn
    spacecraft.turnRight();
    Direction dir = spacecraft.getDirection();
    if (directionToChar(dir) == 'E')
        cout << "Turn test passed\n";
    else
        cout << "Turn test failed\n";

    // Test angle
    spacecraft.turnUp();
    Direction dir1 = spacecraft.getDirection();
    if (directionToChar(dir1) == 'U')
        cout << "Angle test passed\n";
    else
        cout << "Angle test failed\n";
}

int main()
{
    // Initialize spacecraft's initial position and direction
    int x = 0, y = 0, z = 0;
    Direction initialDirection = N;
    string commands;

    // Read a sequence of commands from the user
    cin >> commands;

    Chandrayaan3 spacecraft(x, y, z, initialDirection);

    // Print initial position and direction
    cout << "Starting Position: (" << x << ", " << y << ", " << z << ")" << endl;
    cout << "Initial Direction: " << directionToChar(initialDirection) << endl;

    // Iterate through the commands and move the spacecraft accordingly
    for (char command : commands)
    {
        spacecraft.move(command);
        cout << "\"" << command << "\" - (" << spacecraft.getPosition().x << ", " << spacecraft.getPosition().y << ", " << spacecraft.getPosition().z << ") - " << directionToChar(spacecraft.getDirection()) << endl;
    }

    // Print final position and direction
    cout << "Final Position: (" << spacecraft.getPosition().x << ", " << spacecraft.getPosition().y << ", " << spacecraft.getPosition().z << ")" << endl;
    cout << "Final Direction: " << directionToChar(spacecraft.getDirection()) << endl;

    cout << "\n";
    cout << "\n";

    // Test cases
    runTests();

    return 0;
}
