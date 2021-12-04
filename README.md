# Soccer_simulation
SYDE 121 - A#3 - Q1

Assignment instruction:

According to a report published by Canadian Heritage [Canadian Heritage, 2013], after golf and hockey, soccer is one of the most popular sports in Canada among adults, and it is the most popular sport among children ages 5 to 14.
Source: http://publications.gc.ca/collections/collection_2013/pc-ch/CH24-1-2012-eng.pdf
If you are not familiar with soccer, see the Laws of the Game document published The International Football Association Board (IFAB) [IFAB, 2020]. Source: https://fifa.fans/3knkocx

1. Write a program that simulates a game of soccer where two teams are playing a single game: Team A and Team B.
   A. Your simulator should perform the following:
     - Generate a random number between [1,20], inclusive.
     - This number represents the number of events that occur during the game.
     
   B. For each event, generate a random number between [1,6], inclusive.
     - If the number generated is 1, then Team A has shot at target.
     - If the number generated is 2, then Team B has shot at target.

     o To decide if a goal was scored, additional random number is generated.
     o If the number is 0, then the team has scored a goal. If the number is 1, then the shot was made on goal but was
      saved by the goalkeeper or last defender. If the number is 2, then the shot was made off goal. If the number is 3, then the shot was blocked by a player who
      is not the last defender.
      
     - If the number generated is 3, then Team B has committed a foul and Team A was awarded a free kick.
     - If the number generated is 4, then Team A has committed a foul and Team B was awarded a free kick.

     o To decide if a goal was scored, additional random number is generated.
     o If the number is 0, then the team has scored a goal. If the number is 1, then the shot was made on goal but was
       saved by the goalkeeper or last defender. If the number is 2, then the shot was made off goal. If the number is 3,
       then the shot was blocked by a player who is not the last defender.
     o Additionally, another number is generated to decide if a card was given for the foul. If the number generated is
       0, then no card was given. If the number generated is 1, then a yellow card was given. If the number generated is 2, then a red card was given.
      
     - If the number generated is 5, then Team B has committed a foul close to the goal and Team A was awarded a penalty kick.
     - If the number generated is 6, then Team A has committed a foul close to the goal and Team B was awarded a penalty kick.

     o To decide if a goal was scored, additional random number is generated.
     o If the number is 0, then the team has scored a goal. If the number is 1, then the shot was made on goal but was
       saved by the goalkeeper. If the number is 2, then the shot was made off goal.
     o Additionally, another number is generated to decide if a card was given for the foul. If the number generated is
       0, then no card was given. If the number generated is 1, then a yellow card was given. If the number generated is 2, then a red card was given.
      
   C. For each event that is generated, as it occurs, your program should output a corresponding statement giving adequate commentary on the event (e.g., “Team A
      has scored a goal! Fantastic shot!”). Marks will be awarded for adequately formatted simulator output. An optional time delay may be introduced between
      events.
      
   D. Divide the game into two halves (e.g., 10 events per half, or randomly divide 20 events between two halves), and print out the game stats at the end of each
      half, including the current score, number of shots on goal, shots off goal, blocked shots, fouls, yellow cards, and red cards.

   E. Ensure that srand() function is called when appropriate to randomize the game outcome. For example, call srand() at the start of the game.
   
2. Use top-down problem solving to design a solution for this problem.
   First, perform problem decomposition and identify functions and steps that you need to program, including function declarations. Then, start implementing
   function definitions. Finally, keep the code inside the main() function to a minimum (e.g., invoke start_soccer_simulation()).

3. Verify that your program is correct by by running different simulations of the game. Ensure that all event types can occur, and that a particular game scenario
   is not frequently repeated. Also verify that the outputted stats are correct (e.g., manually count the number of events that occur of each type).
   As a comment at the start of your program (i.e., using /* ... */ notation), explain what testing scenarios you ran as part of testing and debugging, and explain
   any limitations related to your simulation if applicable.
