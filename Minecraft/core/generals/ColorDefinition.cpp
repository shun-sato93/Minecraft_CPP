//
//  ColorDefinition.cpp
//  tetris
//
//  Created by Shun Sato on 7/3/18.
//  Copyright © 2018 佐藤駿. All rights reserved.
//

#include "ColorDefinition.hpp"

#include "Random.hpp"
#include "Utils.hpp"

Color::Types Color::getRandomColor() {
    static auto rand = Random(0);
    return static_cast<Types>(rand.getInt() % 4 + 1);
}
