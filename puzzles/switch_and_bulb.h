#pragma once
#include <array>

namespace puzzles
{
	/** /brief house full of rooms with lights and switches that controll them
	* This puzzle represents a house full of rooms that each have one light.
	* There is a switch board with a switch for each room's light, but they are unlabled.
	* It is gaurenteed that each switch only contols a single light.
	* You can toggle any number of switches with one action (call to ToggleSwitches).
	* You can determine which rooms lights are turned on by one action (call to Observe).
	* @see DetermineSwitchMap is an O(log(n)) algorithm to find the correct mapping between 
	* switches and the controlled lights.
	*/
	template <int size>
	class House
	{
	public:
		/** /brief Reveal which lights in the house are turned on.
		* @return an array representing whether each light in the house is on or off.
		*/
		std::array<bool,size> Observe();


		/** /brief Toggles the switches in the house
		* @param an array whether to toggle each indexed switch
		*/
		void ToggleSwitches(std::array<bool, size> toggled);

		/** /brief Constructor for House object
		* By default all lights in the house are turned off to start.
		* @param switch_to_room_map_ represents 
		* @see switch_to_room_map_
		*/
		House(std::array<int, size > switch_to_room_map): switch_to_room_map_(switch_to_room_map)
		{
			for (int i = 0; i < size; ++i)
			{
				lights_.get(i) = false;
			}
		}

	private:

		/** Array representing the state of lights in the house
		* for a given index true : light is turned on, false : light is turend off.
		*/
		std::array<bool, size> lights_;

		/** At index i is the room number associated with the switch.
		* By toggling switch i, the light at index switch_to_room_map_[i] will change.
		*/
		std::array<int, size> switch_to_room_map_;
	};


	template <int size>
	std::array<bool, size> House::Observe()
	{
		return lights_;
	}


	template <int size>
	void House::ToggleSwitches(std::array<bool, size> toggled)
	{
		for (int i = 0; i < lights_.size(); i++)
		{
			if (toggled.get(i))
			{
				int index_to_flip = switch_to_room_map_.get(i);
				lights_.get(index_to_flip) = !lights_.get(index_to_flip);
			}
		}
	}


	/** /brief Finds the mapping of switches to lights
	* Recursive divide and conquer imp
	* @param The house to be 
	* @return An array with the propety that the ith switch has the index of the room.
	*/
	template<int size>
	std::array<int, size> DetermineSwitchMap(House<size> house)
	{

	}

}
