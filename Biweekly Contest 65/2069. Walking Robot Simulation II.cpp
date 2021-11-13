class Robot {
public:
   string dir;
    int width,height,x,y;
    Robot(int width, int height) {
        this->width=width-1;
        this->height=height-1;
        x=0,y=0,dir="East";
    }
    
    void move(int num) {
        // cout<<width<<" "<<height<<" ";
        num=(num>=(2*height+2*width))?(num%(2*height+2*width)):num;
        if(num==0 and x==0 and y==0)dir="South";
        while(num){
            if(dir=="East"){
               if(x+num>width)
               {
                   num=num-width+x;
                   x=width;
                   dir="North";
               }
              else{
                  x=x+num;
                  num=0;
              }
            }else if(dir=="North"){
                if(y+num>height)
               {
                   num=num-height+y;
                   y=height;
                   dir="West";
               }
              else{
                  y=y+num;
                  num=0;
              }
            }
            else if(dir=="West"){
                if(x-num<0)
               {
                   num=num-x;
                   x=0;
                   dir="South";
               }
              else{
                  x=x-num;
                  num=0;
              }
            }
            else if(dir=="South"){
            if(y-num<0)
               {
                   num=num-y;
                   y=0;
                   dir="East";
               }
              else{
                  y=y-num;
                  num=0;
              }
            }
        }
        // cout<<x<<" "<<y<<endl;
        
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
