/*
  ==================================================================================================================

    Functions.h
    Created: 10 Feb 2022 8:11:21pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>

/// <summary>
/// Contains static functions for application-wide use.
/// </summary>
namespace app {
    template<class ComponentClass>
    static ComponentClass* getChildComponentOfClass(juce::Component* parent);
}

/// <summary>
/// Recursively searches for any component of type ComponentClass in the parent's child hierarchy. 
/// Similar to the findParentComponentOfClass but in reverse.
/// </summary>
/// <typeparam name="ComponentClass">The type of the child to look for.</typeparam>
/// <param name="parent">The parent on which to execute the search.</param>
/// <returns>The child component if found, nullptr otherwise.</returns>
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
