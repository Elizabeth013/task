#include <iostream>
#include <string>
#include <new>
#include <assert.h>

//Ассоциативный массив
template <typename K, typename T>

class m_array {
 
    struct info {
        K key;
        T data;
    };
 
private:
    info* arr;
    int  count;
    int  m;
public:
    m_array (void) : arr(NULL), count(0), m(14) {}
    ~m_array(){
        this->clear();
    }
 
    m_array(const m_array&);
    m_array& operator = (const m_array&);
public:
 
    //добавление значения(ключа)
    T* add (const K& key, const T& data) {
        int i = bin_find(key);
        if(! heap_allocation()) return NULL;
 
        if(key == arr[i].key) return NULL;
        
        if(i < count){
            info* pb = arr + count;
            info* pa = arr + i;
            for(;pb > pa; pb--) *pb = *(pb - 1); 
        }
        arr[i].key  = key;
        arr[i].data = data;
        
        count++;
        return &arr[i].data;
    }
 
    //удаление элемента по ключу
    void remove(const K& key){
        int i = bfind_info(key);
        if(i != (int)-1){
            count--;
            info* pa = arr + i;
            info* pb = arr + count;
            for(;pa < pb; pa++) *pa = *(pa + 1);
 
            if(! count)
                this->clear();
        }
    }
 
    //поиск элемента по ключу 
    T* find(const K& key){
        int i = bfind_info(key);
        return (i != (int)-1) ? &arr[i].data : NULL;
    }
    const T* find(const K& key) const {
        const int i = bfind_info(key);
        return (i != (int)-1) ? &arr[i].data : NULL;
    }
 
    bool empty(void) const {
        return (arr == NULL);
    }
 
    //размер ассоциативного массива
    int size(void) const {
        return count;
    }
    //удаление всего массива
    void clear(void) {
        if(arr != NULL)
        delete[] arr;
        arr = NULL;
        count = 0;
        m = 14;
    }
    //получение ключа по индексу только для чтения
    const K& keyread(int i) const {
        return arr[i].key;
    }
 
    //доступ к значению по индексу
    T& valueread(int i) const {
        return arr[i].data;
    }
 
    //получение доступа как к обычному массиву
    const T& operator [] (const K& key) const {
        const int i = bfind_info(key);
 
        assert(i != (int)-1);
        return arr[i].data;
    }
 
    T& operator [] (const K& key){
        int i = bin_find(key);
        if((i < count) && (key == arr[i].key))
            return arr[i].data;
        
        if(heap_allocation()){
            if(i < count){
                info* pb = arr + count;
                info* pa = arr + i;
                for(;pb > pa; pb--)
                    *pb = *(pb - 1); 
            }
            arr[i].key  = key;
            arr[i].data = T();
            count++;
        } else
            assert(false);
 
        return arr[i].data;
    }
 
private:
 
    //выделение динамической памяти для массива
    bool heap_allocation(void){
        if(arr == NULL){
            arr = new (std::nothrow) info[m];
            if(arr == NULL)
                return false;
        } else if((count + 1) >= m){
            int  tm = count + m / 2;
            info* tmp  = new (std::nothrow) info[tm];
            if (tmp == NULL) return false;
            
            const info* p = arr;
            const info* e = arr + count;
            info* d = tmp;
            while(p != e)  *d++ = *p++;
 
            delete[] arr;
            arr = tmp;
            m = tm;
        }
        return true;
    }
 
    //двоичный поиск вхождение ключа для вставки
    int bin_find(const K& key){
        if(! count || (key < arr[0].key)) return 0;
        else if(arr[count - 1].key < key) return count;
        int d = 0, f = 0, l = count;
        while(f < l){
            d = (f + l) >> 1;
            if(key < arr[d].key)   l = d;
            else {
                if(key == arr[d].key)  return d;
                f = d + 1;
            }
        }
        return f;
    }
 
    //двоичный поиск вхождения ключа
    int bfind_info(const K& key) const {
        if(! count || (key < arr[0].key))  return (int)-1;
        else if(arr[count - 1].key < key)  return (int)-1;
        int d = 0, f = 0, l = count;
        while(f < l){
            d = (f + l) >> 1;
            if(key < arr[d].key)
                l = d;
            else {
                if(key == arr[d].key)
                    return d;
                f = d + 1;
            }
        }
        return (int)-1;
    }
};
 
 
 
int main(void){
    m_array<std::string, int> arr;
 
    arr["А"] = 100;
    arr["Б"] = 200;
    arr["В"] = 300;
    arr["Г"] = 400;
    arr["Д"] = 500;
 
    //найти Б
    int* p = arr.find("Б");
    if(p != NULL) *p = 1;
        
    //удалим Б
    arr.remove("");
    if(arr.find("Б") == NULL) std::cout << "удалили Б" << std::endl;
 
    //добавим Е
    arr.add("Е", 600);
 
    //вывести все элементы с ключами
    for(int i = 0; i < arr.size(); ++i) {
        std::cout << arr.keyread(i)   << " = " << arr.valueread(i) << std::endl;
    }
    std::cout << std::endl;
    return 0;
}