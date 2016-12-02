#include "shared_ptr.cpp"

Storage::Storage(Matrix* mtx){
    data_ = mtx;
    ref_count_ = 1;
}

Storage::~Storage(){
    delete(data_);
}

Storage::void incr(){
    ref_count_++;
}
Storage::void decr(){
    ref_count_--;
}

Storage::int getCounter() const{
    return ref_count_;
}
Storage::Matrix* getObject() {
    return data_;
}

shared_ptr::shared_ptr(Matrix* obj){
    storage_ = new Storage(obj);
}

shared_ptr::shared_ptr(const shared_ptr& other){
    storage_ = other.storage_;
    storage_.incr();
}

shared_ptr::shared_ptr& operator=(shared_ptr other){
    shared_ptr tmp = shared_ptr(other);
    std::swap(storage_, tmp.storage_);
    return *this;
}

shared_ptr::~shared_ptr(){
    storage_.decr();
    if (!storage_.getCounter())  delete(storage_);
}

shared_ptr::Matrix* ptr() const{
    return storage_.getObject();
}

shared_ptr::bool isNull() const{
     if (storage_.getObject()) return false;
     return true;
}

shared_ptr::void reset(Matrix* obj){
   tmp = shared_ptr(obj);
   std::swap(storage_, tmp.storage_);
   return *this;
}

shared_ptr::Matrix* operator->() const{
    return storage_.getObject();
}

shared_ptr::Matrix& operator*() const{
     return *storage_.getObject();
}
