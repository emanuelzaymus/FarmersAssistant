#pragma once

#include <math.h>

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{

	/// <summary> Triedenie Shell sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class ShellSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Shell sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
		void sortWstring(UnsortedSequenceTable<K, T>& table);
	};

	template<typename K, typename T>
	inline void ShellSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		for (int gap = ceil(table.size()) / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < table.size(); i++)
			{
				auto temp = table.getItemAtIndex(i);

				int j;
				for (j = i; j >= gap && table.getItemAtIndex(j - gap).getKey() > temp.getKey(); j -= gap) {
					table.getItemAtIndex(j) = table.getItemAtIndex(j - gap);
				}
				table.getItemAtIndex(j) = temp;
			}
		}
	}

	template<typename K, typename T>
	inline void ShellSort<K, T>::sortWstring(UnsortedSequenceTable<K, T>& table)
	{
		for (int gap = ceil(table.size()) / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < table.size(); i++)
			{
				auto temp = table.getItemAtIndex(i);

				int j;
				for (j = i; j >= gap && static_cast<std::wstring>(table.getItemAtIndex(j - gap).getKey()).compare((std::wstring)temp.getKey()) > 0; j -= gap) {
					table.getItemAtIndex(j) = table.getItemAtIndex(j - gap);
				}
				table.getItemAtIndex(j) = temp;
			}
		}
	}

}