//
//  GameContext.hpp
//  tetris
//
//  Created by Shun Sato on 7/2/18.
//  Copyright © 2018 佐藤駿. All rights reserved.
//

#ifndef GameContext_hpp
#define GameContext_hpp

#include "Singleton.hpp"
#include "InputHandleable.hpp"

class GameMode;
class Camera;

/**
 * This class holds variables that is used by entire game and the top level game objects such as GameMode.
 * To start a game, call createPlayer() or createAIPlayer()
 * Singleton.
 */
class GameContext: public Singleton<GameContext> {
public:
    ~GameContext();
    
    void openUDP();
    
    /**
     * show title screen
     */
    void goTitle();
    
    void setPauseGame(bool isPaused);
    
    /**
     * Calling following functions instantiates Player class, and starts a game.
     */
    void startGame(GameMode* gameMode);
    void openGameMeneWindow();
    
    /**
     * quitGame() deletes Player instance and quits a game.
     */
    void quitGame();
    
    GameMode* getGameMode();
    
    void handleInput(const Input::Data& inputData);
private:
    friend class Singleton<GameContext>;
    GameContext();
    
    GameMode* gameMode;
};

#endif /* GameContext_hpp */
