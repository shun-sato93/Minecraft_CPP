//
//  IOInterface.cpp
//  tetris
//
//  Created by Shun Sato on 7/2/18.
//  Copyright © 2018 佐藤駿. All rights reserved.
//

#include "IOInterface.hpp"

#include "Constants.hpp"
#include "GameContext.hpp"
#include "GameMode.hpp"
#include "opengl.hpp"

void IOInterface::drawRectangle(double x1, double y1, double width, double height, Color::Types color, bool fill) {
//    OpenGL::drawRectangle(color, x1, y1, x1+width, y1+height, fill);
}

void IOInterface::drawText(double x, double y, const std::string& text, Color::Types color) {
//    OpenGL::drawText(x, y, text, color);
}

void IOInterface::keyboardInput(Keyboard::Types input) {
//    auto gameMode = GameContext::get().getGameMode();
//    if (gameMode != nullptr) {
//        gameMode->handleInput(input);
//    }
}

void IOInterface::changeWindowSize(int width, int height) {
//    OpenGL::changeWindowSize(width, height);
}

Size IOInterface::getTextSize(const std::string& text, int font) {
    return Size(0, 0);//OpenGL::getTextSize(text, font);
}

void IOInterface::moveCamera(const vec2d& centerCoordinates) {
//    OpenGL::moveCamera(centerCoordinates);
}
