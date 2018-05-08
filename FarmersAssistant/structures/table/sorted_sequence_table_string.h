#pragma once

#include "../list/array_list.h"
#include "sequence_table.h"

namespace structures
{

	/// <summary> Utriedena sekvencna tabulka. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class SortedSequenceTableString : public SequenceTable<K, T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		SortedSequenceTableString();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> SortedSequenceTableString, z ktorej sa prevezmu vlastnosti. </param>
		SortedSequenceTableString(const SortedSequenceTableString<K, T>& other);

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat udajovej struktury. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override;

		/// <summary> Vlozi data s danym klucom do tabulky. </summary>
		/// <param name = "key"> Kluc vkladanych dat. </param>
		/// <param name = "data"> Vkladane data. </param>
		/// <exception cref="std::logic_error"> Vyhodena, ak tabulka uz obsahuje data s takymto klucom. </exception>  
		void insert(const K& key, const T& data) override;
	protected:
		/// <summary> Najde prvok tabulky s danym klucom. </summary>
		/// <param name = "key"> Hladany kluc. </param>
		/// <returns> Prvok tabulky s danym klucom, ak neexistuje, vrati nullptr. </returns>
		TableItem<K, T>* findTableItem(const K& key) const override;
	private:
		/// <summary> Najde index prvku s danym klucom. Kontroluje rozsah [indexStart, indexEnd). Pracuje na principe bisekcie. </summary>
		/// <param name = "key"> Hladany kluc. </param>
		/// <param name = "indexStart"> Pociatocny index prehladavanej sekvencie. </param>
		/// <param name = "indexEnd"> Koncovy index prehladavanej sekvencie. </param>
		/// <param name = "found"> Vystupny parameter, ktory indikuje, ci sa kluc nasiel. </param>
		/// <returns> Index prvku s danym klucom. Ak sa kluc v tabulke nenachadza, vrati index, kde by sa mal prvok s takym klucom nachadzat. </returns>
		int indexOfKey(const K& key, int indexStart, int indexEnd, bool& found) const;
	};

	template<typename K, typename T>
	inline SortedSequenceTableString<K, T>::SortedSequenceTableString() :
		SequenceTable<K, T>(new ArrayList<TableItem<K, T>*>())
	{
	}

	template<typename K, typename T>
	inline SortedSequenceTableString<K, T>::SortedSequenceTableString(const SortedSequenceTableString<K, T>& other) :
		SortedSequenceTableString()
	{
		*this = other;
	}

	template<typename K, typename T>
	inline Structure * SortedSequenceTableString<K, T>::clone() const
	{
		return new SortedSequenceTableString<K, T>(*this);
	}

	template<typename K, typename T>
	inline void SortedSequenceTableString<K, T>::insert(const K & key, const T & data)
	{
		bool found = false;
		int index = indexOfKey(key, 0, list_->size(), found);
		if (!found)
		{
			list_->insert(new TableItem<K, T>(key, data), index);
		}
		else {
			throw std::exception("Key is already in the table.");
		}
	}

	template<typename K, typename T>
	inline TableItem<K, T>* SortedSequenceTableString<K, T>::findTableItem(const K & key) const
	{
		if (size() == 0)
		{
			return false;
		}
		bool found = false;
		int index = indexOfKey(key, 0, size(), found);
		return found ? (*list_)[index] : nullptr;
	}

	template<typename K, typename T>
	inline int SortedSequenceTableString<K, T>::indexOfKey(const K & key, int indexStart, int indexEnd, bool & found) const
	{
		if (indexStart == size())
		{
			found = false;
			return size();
		}
		int center = (indexStart + indexEnd) / 2;
		std::wstring keyAtPivot = (std::wstring)(*list_)[center]->getKey();

		if (keyAtPivot.compare(key) == 0)
		{
			found = true;
			return center;
		}
		else
		{
			if (indexStart == indexEnd)
			{
				found = false;
				return keyAtPivot.compare(key) > 0 ? center : center + 1;
			}
			else
			{
				if (keyAtPivot.compare(key) < 0)
					indexStart = center + 1;
				else
					indexEnd = center;
				return indexOfKey(key, indexStart, indexEnd, found);
			}
		}
	}
}