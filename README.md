# Factory Management Simulator

Dive into the world of manufacturing with the Factory Management Simulator, where you, as an enterprising entrepreneur, have set up a new car factory. With a 30-day window, your goal is to make strategic investments in workers and machines to maximize profits. But be wary, as each unit comes with its unique set of advantages and challenges. 

## Game Description

In this simulation game, players manage a car factory with the objective to turn it into a profitable venture within 30 days. You have the choice to hire workers or buy machines each day, each contributing differently to your production capabilities. Workers increase their experience over time and can be promoted to head workers, enhancing the efficiency of your operation. Machines can boost your production significantly but come with the risk of failure and repair costs. Strategic decision-making is key to avoiding bankruptcy and succeeding in this challenging simulation.

## Class Structure

Your role will involve managing the following entities:

- **Unit:** The base class for workers and machines, encapsulating common attributes.
- **Worker:** A class representing factory workers, who gain experience over time and can be promoted to head workers, affecting overall productivity.
- **Machine:** Machines contribute high returns but carry the risk of failure and associated repair costs.
- **Head Worker:** A class for experienced workers that provide higher returns. Workers are automatically promoted to head workers upon reaching sufficient experience.
- **Factory:** This class manages workers, head workers, and machines. It's responsible for simulating the passing of days, including promotions and financial updates.
- **Simulation:** Handles user interface and interactions, such as hiring workers, buying machines, and advancing days.

## Gameplay

- Make daily decisions to hire workers, buy machines, or skip days.
- Manage your capital carefully and monitor the daily costs and returns of your units.
- Balance short-term gains with long-term investments to grow your factory.

## Compilation and Execution

To compile and run the game, use the following commands in your terminal:

```bash
g++ -Wall -Werror src/*.cpp -Iinclude -o bin/main
./bin/main
