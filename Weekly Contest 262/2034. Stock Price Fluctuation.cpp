class StockPrice {
public:
    int curr;
    map<int,int>ma;
    set<pair<int,int>>s;
    StockPrice() {
        curr=0;
        ma.empty();
        s.empty();
    }
    
    void update(int timestamp, int price) {
        if(ma.find(timestamp)==ma.end()){
            ma[timestamp]=price;
            curr=price;
            s.insert({price,timestamp});
        }else{
            auto f=s.find(make_pair(ma[timestamp],timestamp));
            curr=price;
            if(f!=s.end())
             s.erase(f);
            ma[timestamp]=price;
            s.insert({price,timestamp});
        }
        
        
    }
    
    int current() {
        return((*ma.rbegin()).second);
    }
    
    int maximum() {
        pair<int,int>temp=*s.rbegin();
        return temp.first;
    }
    
    int minimum() {
        pair<int,int>temp=*s.begin();
        return temp.first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
