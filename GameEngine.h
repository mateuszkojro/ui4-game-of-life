//
// Created by mateu on 3/22/2021.
//

#ifndef GAME_OF_LIFE_GAMEENGINE_H
#define GAME_OF_LIFE_GAMEENGINE_H

/// \brief Base class for custom game engines
class GameEngine {
public:

    /// \brief Config for game engines
    struct Config {
        int framerate;
    } current_config_;

    /// We dont wanna allow copying our game engine
    GameEngine() = delete;

    /// We dont wanna allow copying our game engine
    GameEngine(const GameEngine &) = delete;

    const GameEngine &operator=(const GameEngine &) = delete;

    /// \brief when we create a GameEngine we always need to give it a config
    explicit GameEngine(const GameEngine::Config &config) :
            current_config(config) {};

    /// \brief This function is called on game start
    virtual void on_start() = 0;

    /// \brief This function will be invoked on every world tick
    virtual void on_tick() = 0;

    /// \brief This function is called when the game ends
    virtual void on_end() = 0;

    virtual ~GameEngine() = default;

};


#endif //GAME_OF_LIFE_GAMEENGINE_H
