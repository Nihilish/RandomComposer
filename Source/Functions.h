/*
  ==============================================================================

    Functions.h
    Created: 10 Feb 2022 8:11:21pm
    Author:  simon_i7fbffu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace app {
    template<class ComponentClass>
    static ComponentClass* getChildComponentOfClass(juce::Component* parent);
}

template<class ComponentClass>
ComponentClass* app::getChildComponentOfClass(juce::Component* parent)
{
    for (int i = 0; i < parent->getNumChildComponents(); ++i)
    {
        auto* childComp = parent->getChildComponent(i);

        if (auto c = dynamic_cast<ComponentClass*> (childComp))
            return c;

        if (auto c = getChildComponentOfClass<ComponentClass>(childComp))
            return c;
    }

    return nullptr;
}
