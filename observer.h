/
// Created by boris nono  il 25/02/2024.
//

#ifndef NONO_LABPROGRAMMAZIONE_OBSERVER_H
#define NONO_LABPROGRAMMAZIONE_OBSERVER_H

#include <string>
using namespace std;

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(const string& listName) = 0;
};

#endif //NONO_LABPROGRAMMAZIONE_OBSERVER_H
