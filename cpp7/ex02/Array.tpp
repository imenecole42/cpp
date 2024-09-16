
template <typename T>
Array<T>::Array():val(NULL),size(0){val=new T[0];}

template <typename T>
Array<T>::Array(unsigned int n):size(n)
{val = new T[n];}
template <typename T>
Array<T>::Array(const Array<T>& cpy):size(cpy.size)
{        
	val = new T[size];
	for (unsigned int i = 0; i < size; i++) {
            val[i] = cpy.val[i];
        }
}
template <typename T>
Array<T> &Array<T>::operator=(const Array<T>& cpy) 
{
	if(this != &cpy)
	{
		delete[] val;
		size = cpy.size;
		val = new T[size];
		for (unsigned int i = 0; i < size; i++) 
            val[i] = cpy.val[i];
	}
	return(*this);

}
template <typename T>
Array<T>::~Array()
{ delete[] val ;}

template <typename T>
T & Array<T>:: operator[](unsigned int i) 
{
    if (i >= size)
	{
        throw std::out_of_range("Index hors limites");
        
	}
    return val[i];
}
template <typename T>
unsigned int Array<T> ::getSize() const {
        return (size);
}