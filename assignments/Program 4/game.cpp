/******************************************************
** Program: game.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for game class
** Input:
** Output:
******************************************************/
#include "game.h"


/*****************************************************************************
 * function: Game
 * description: game constructor
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
Game::Game(int size){
    grid_size = size;
    int start_x = rand() % grid_size; //randomly picks a starting position on the grid
    int start_y = rand() % grid_size;
    player = new Player(start_x, start_y, grid_size); //creates a player
    wumpus_alive = true;

    g = new Gold; //event pointers
    p = new Pit;
    b = new Bats;
    wump = new Wumpus;

    Room empty; //room object that points to null

    for(int i=0; i < grid_size; i++){
        grid.push_back(vector<Room>{});
        for(int j=0; j < grid_size; j++){
            grid[i].push_back(empty);
        }
    }
}

/*****************************************************************************
 * function: ~Game
 * description: game desctructor 
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
Game::~Game(){
    delete this->g;
    delete this->b;
    delete this->p;
    delete this->wump;
    delete this->player;
}

/*****************************************************************************
 * function: print_grid
 * description: prints the grid without showing events
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::print_grid(){
for(int i=0; i < grid_size; i++){
    for(int j=0; j < grid_size; j++){
        cout << "+---";
    }
    cout << "+" << endl;
    for(int t=0; t < 3; t++){
        cout << "|" ;
        for(int p=0; p < grid_size; p++){
            if(p == player->get_currentx() && i == player->get_currenty() && t == 1){
                cout << " * |";
            }else{cout << "   |";}
        }
    cout << endl;
    }
}
for(int j=0; j < grid_size; j++){
    cout << "+---";
}
cout << "+" << endl;
}

/*****************************************************************************
 * function: print_debug
 * description: prints the grid with events showing
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::print_debug(){
for(int i=0; i < grid_size; i++){
    for(int j=0; j < grid_size; j++){
        cout << "+---";
    }
    cout << "+" << endl;
    for(int t=0; t < 3; t++){
        cout << "|" ;
        for(int p=0; p < grid_size; p++){
            bool placed = false;
            if(p == player->get_currentx() && i == player->get_currenty() && t == 1){
                cout << " * |"; placed=true;
            }
            if((p == player->get_startx() && i == player->get_starty()) && (player->get_startx() != player->get_currentx() || player->get_currenty() != player->get_starty()) && t == 1){
                cout << " o |"; placed = true;
            }
            if(grid[p][i].get_event() > 0 && t==1){
                cout << " "; this->grid[p][i].debug_symbol(); cout << " |"; placed=true;
            }
            else if(placed == false){
                cout << "   |"; 
            }
        }
    cout << endl;
    }
}
for(int j=0; j < grid_size; j++){
    cout << "+---";
}
cout << "+" << endl;
}

/*****************************************************************************
 * function: place_events
 * description: radomly places events on to the grid
 * pre-conditions: event type
 * post-conditions: radomly placed events
 * **************************************************************************/
void Game::place_events(int type){
    int row, col;
    do{
        row = rand() % grid_size;
        col = rand() % grid_size;
    }while(grid[row][col].get_event() != -1 || (row == player->get_startx() && col == player->get_starty()));

    if(type == 1){
        grid[row][col].set_room(g); //place gold event
    }
    if(type == 2){
        grid[row][col].set_room(p); //place pit event
    }
    if(type == 3){
        grid[row][col].set_room(b); //place bats
    }
    if(type == 4){
        grid[row][col].set_room(wump); //place wumpus
    }
}

/*****************************************************************************
 * function: fill_grid
 * description: calls the place_event function by passing the event type
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::fill_grid(){
    place_events(1); // places gold on map
    place_events(2); place_events(2); //places 2 pits on map
    place_events(3); place_events(3); //places 2 bat caves on map
    place_events(4); // places wumpy on the map
}

/*****************************************************************************
 * function: awake_wumpus
 * description: wakes up wumpus, moves him to a new position with 75% probability
 * pre-conditions:
 * post-conditions: newly positioned wumpus
 * **************************************************************************/
void Game::awake_wumpus(){
    cout << "Your arrow woke up Wumpus!" << endl;
    int rand_num = rand() % 4; //75% chance wumpy will relocate
    if(rand_num != 0){
        cout << "The earth is shaking! Wumpus must be relocating..." << endl;
        int wx, wy;
        for(int i=0; i < grid_size; i++){
            for(int j=0; j < grid_size; j++){
                if(grid[i][j].get_event() == 4){
                    wx = i;
                    wy = j;
                }
            }   
        }
        grid[wx][wy].set_room(NULL);
        place_events(4);
    }
}

/*****************************************************************************
 * function: check_for_event
 * description: checks for events adjacent to the player's current position
 * pre-conditions:
 * post-conditions: returns the type of event adjacent to player
 * **************************************************************************/
int Game::check_for_event(int dx, int dy){
    int xp = player->get_currentx(), yp = player->get_currenty();
    if((xp + dx >= grid_size) || (xp + dx) < 0){
        return -1;
    }
    else if((yp + dy) >= grid_size || (yp + dy) < 0){
        return -1;
    }
    else{
        return grid[xp + dx][yp + dy].get_event();
    }
}

/*****************************************************************************
 * function: get_percept
 * description: calls the events' percepts
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::get_percept(int dx, int dy){
    int xp = player->get_currentx(), yp = player->get_currenty();
    if( (xp + dx) >= grid_size || (xp + dx) < 0){
        return;
    }
    else if( (yp + dy) >= grid_size || (yp + dy) < 0){
        return;
    }
    else{
        if(grid[xp + dx][yp + dy].get_event() != -1){ //if vector contains an event adjacent to player
            grid[xp + dx][yp + dy].get_percept(); //call percept
        }
    }
}

/*****************************************************************************
 * function: shoot_arrow_north
 * description: shoots the arrow north of player
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::shoot_arrow_north(){
bool arrow_hit = false;
    for(int i=1; i <= 3; i++){
        if( (player->get_currenty() - i) == -1){ //arrow out of map
            cout << "Your arrow hit a wall." << endl;
            arrow_hit = true;
            return;
        }
        if( check_for_event(0, i*-1) == 4){ // if arrow passes through Wumpus' room
            wumpus_alive = false; //arrow kills him
            kill_wump();
            arrow_hit = true;
            return;
        }
        if(check_for_event(-1, i*-1) == 4 || check_for_event(1, i*-1) == 4){ //if arrow passes adjacent room to Wumps
            awake_wumpus(); //wake him up
        }
        if(arrow_hit == false && i == 3){
            cout << "Your arrow did not hit anything." << endl;
        }
    }
}

/*****************************************************************************
 * function: shoot_arrow_south
 * description: shoots an arrow south of player
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::shoot_arrow_south(){
    bool arrow_hit = false;
    for(int i=1; i <= 3; i++){
        if( (player->get_currenty() + i) == grid_size){
            cout << "Your arrow hit a wall." << endl;
            arrow_hit = true;
            return;
        }
        if( check_for_event(0, i) == 4){
            wumpus_alive = false;
            kill_wump();
            arrow_hit = true;
            return;
        }
        if(check_for_event(-1, i) == 4 || check_for_event(1, i) == 4){
            awake_wumpus();
            return;
        }
        if(arrow_hit == false && i ==3){
            cout << "Your arrow did not hit anything." << endl;
        }
    }
}

/*****************************************************************************
 * function: shoot_arrow_west
 * description: shoots arrow west of player
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::shoot_arrow_west(){
    bool arrow_hit = false;
    for(int i=1; i <= 3; i++){
        if( (player->get_currentx() - i) == -1){
            cout << "Your arrow hit a wall." << endl;
            arrow_hit = true;
            return;
        }
        if( check_for_event(i*-1, 0) == 4){
            wumpus_alive = false;
            kill_wump();
            arrow_hit = true;
            return;
        }
        if(check_for_event(i*-1, -1) == 4 || check_for_event(i, 1) == 4){
            awake_wumpus();
            return;
        }
        if(arrow_hit == false && i ==3){
            cout << "Your arrow did not hit anything." << endl;
        }
    }
}

/*****************************************************************************
 * function: shoot_arrow_east
 * description: shoots an arrow east of player
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::shoot_arrow_east(){
    bool arrow_hit = false;
    for(int i=1; i <= 3; i++){
        if( (player->get_currentx() + i) == grid_size){
            cout << "Your arrow hit a wall." << endl;
            arrow_hit = true;
            return;
        }
        if( check_for_event(i, 0) == 4){
            wumpus_alive = false;
            kill_wump();
            arrow_hit = true;
            return;
        }
        if(check_for_event(i, -1) == 4 || check_for_event(i, 1) == 4){
            awake_wumpus();
            return;
        }
        if(arrow_hit == false && i ==3){
            cout << "Your arrow did not hit anything." << endl;
        }
    }
}

/*****************************************************************************
 * function: shoot_arrow
 * description: calls appropriate arrow function based on users input
 * pre-conditions: players desired direction as a char
 * post-conditions:
 * **************************************************************************/
void Game::shoot_arrow(char direc){
    int arrow_distance = 0;
    if(player->get_arrows() == 0){
        cout << "You do not have anymore arrows " << endl;
        return;
    }
    player->remove_arrow();
    if(direc == 'w' || direc == 'W'){
        shoot_arrow_north();
    }
    if(direc == 's' || direc == 'S'){
        shoot_arrow_south();
    }
    if(direc == 'a' || direc == 'A'){
        shoot_arrow_west();
    }
    if(direc == 'd' || direc == 'D'){
        shoot_arrow_east();
    }
}

/*****************************************************************************
 * function: kill_wump
 * description: removes wump from the grid
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::kill_wump(){
    int wx, wy;
    for(int i=0; i < grid_size; i++){
        for(int j=0; j<grid_size; j++){
            if(grid[i][j].get_event() == 4){
                wx = i;
                wy = j;
            }
        }
    }
    grid[wx][wy].set_room(NULL);
    cout << "Your arrow pierced the heart of Wumpus!" << endl;
}

/*****************************************************************************
 * function: encounters
 * description: checks if players current room has an event, if so, calls event's encounter function
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::encounters(){
    if(check_for_event(0,0) == 1 || check_for_event(0,0) == 2 || check_for_event(0,0) == 4){ //if event is gold, pit, or wumpus
        grid[player->get_currentx()][player->get_currenty()].get_encounter(this->player); //call encounter
        grid[player->get_currentx()][player->get_currenty()].set_room(NULL); //remove from map
    }
    if(check_for_event(0,0) == 3){ //if bats
        grid[player->get_currentx()][player->get_currenty()].get_encounter(this->player); //call bats encounter
        grid[player->get_currentx()][player->get_currenty()].set_room(NULL); //remove event
        player->bats_move(); //randomly move player
        encounters(); //call this function again to check if player's new room has events
    }    
}

/*****************************************************************************
 * function: get_percepts
 * description: calls percepts adjacents to player
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::get_percepts(){
    get_percept(0,1);
    get_percept(1,0);
    get_percept(-1,0);
    get_percept(0,-1);
}

/*****************************************************************************
 * function: move_player
 * description: moves player if direction is not out of bounds
 * pre-conditions: players input as a char
 * post-conditions:
 * **************************************************************************/
void Game::move_player(char direc){
    bool valid = check_move(direc);
    while(valid == false){
        cin >> direc;
        valid = check_move(direc);
    }
    player->move_player(direc);
}

/*****************************************************************************
 * function: make_move
 * description: prompts the player to move or shoot an arrow
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Game::make_move(){
    cout << "use w,a,s,d to move. press space to shoot arrow." << endl;
    char move = getchar();
    if(move != ' '){
        move_player(move);
    }
    if(move == ' '){
        char arr;
        cout << "Which direction? ";
        cin >> arr;
        shoot_arrow(arr);
    }
}

/*****************************************************************************
 * function: check_win
 * description: checks if player has gold and is in escape room
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
bool Game::check_win(){
    if(((player->get_currentx() == player->get_startx() ) && (player->get_currenty() == player->get_starty())) && player->check_gold() == true){
        cout << "Congratulations! You escaped Wumpus' cave!" << endl;
        return true;
    }else{
        return false;
    }
}

/*****************************************************************************
 * function: check_life
 * description: checks if player is dead
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
bool Game::check_life(){
    return player->check_life();
}

/*****************************************************************************
 * function: check_move
 * description: checks if players desired direction is out of bounds
 * pre-conditions: user input
 * post-conditions: returns boolean
 * **************************************************************************/
bool Game::check_move(char move){
    if(move == 'a' || move == 'A'){
        if( (player->get_currentx()-1) < 0 ){
            return false;
        }
    }
    if(move == 'd' || move == 'D'){
        if( (player->get_currentx()+1) == grid_size ){
            return false;
        }
    }
    if(move == 'w' || move == 'W'){
        if( (player->get_currenty()-1) < 0 ){
            return false;
        }
    }
    if(move == 's' || move == 'S'){
        if( (player->get_currenty()+1) == grid_size ){
            return false;
        }
    }
return true;    
}