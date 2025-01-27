#pragma once

template<typename T, typename U>
class MyPair
{
public:

	T first;
	U second;

	MyPair(const T& _val1, const U& _val2);

	void Swap( MyPair& pair);

};

template<typename T, typename U>
MyPair<T, U>::MyPair(const T& _val1, const U& _val2) : first(_val1), second(_val2) {

}

template<typename T, typename U>
void MyPair<T, U>::Swap( MyPair& pair) {
	T tempFirst = first;
	first = pair.first;
	pair.first = tempFirst;

	U tempSecond = second;
	second = pair.second;
	pair.second = tempSecond;
}
