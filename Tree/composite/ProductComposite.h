#ifndef PRODUCT_COMPOSITE_H
#define PRODUCT_COMPOSITE_H

// Composite
class ProductComponent{
    public:
        virtual int getPrice() = 0;
        void add(ProductComponent component) {};
        void remove(ProductComponent component) {};
        ProductComponent* getChild(int index) {};

        ~ProductComponent(){};
};


#endif