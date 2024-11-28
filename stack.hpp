#include <optional>
#include <sstream>
#include <memory>
using namespace std;

namespace dzunni
{
    /**
     * @author dzunni
     * @brief A Stack data structure created by a beginner for C++.
     */
    template<typename E>
    class Stack {
    private:
        struct Data {
            E element;
            shared_ptr<Data> next;

            Data(const E& e, shared_ptr<Data> n = nullptr){
                element = e;
                next = n;
            }
        };

        shared_ptr<Data> _head;
        size_t _size = 0;
    public:

        Stack(){

        }

        size_t size(){
            return _size;
        }

        void push(const E& element){
            _head = make_shared<Data>(element, _head);
            _size++;
        }

        optional<E> pop(){
            if(_size == 0)
                return nullopt;
            E& element = _head->element;
            _head = _head->next;
            _size--;
            return element;
        }

        bool contains(const E& element){
            shared_ptr<Data> current = _head;
            while(current){
                if(current->element == element)
                    return true;
                current = current->next;
            }
            return false;
        }

        string asString(){
            ostringstream oss;
            oss << '{';
            shared_ptr<Data> current = _head;
            while(current){
                oss << current->element;
                if(current->next)
                    oss << ", ";
                current = current->next;
            }
            oss << '}';
            return oss.str();
        }
    };
} // namespace dzunni
