#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


int binarySearch(vector<int> v, int x) 
{ 
    int low =0;
    int high = v.size();

  
	
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (v[mid] == x)
      return mid;

    if (v[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

void ins(vector<int> &v , int d)
{
    int index = 0;
    for(int i =0; i<d; i++)
    {
        if(v[i]<d){index += 1;}
        else{break;}
    }
   v.insert(v.begin() + index,d);
    
}

vector<int> merge(vector<int> &a, vector <int> &b)
{
    vector <int> vec3;
    int i =0;
    int j=0;
    while(i < a.size() and j <b.size())
    {
        if(a[i] < b[j]){vec3.push_back(a[i]); i++;}
        else if(b[j] < a[i]){vec3.push_back(b[j]); j++;}
        else{vec3.push_back(a[i]); i++; j++;}
    }

    while(i < a.size())
    {
        vec3.push_back(a[i]);
        i++;
    }

    while(j < b.size())
    {
        vec3.push_back(b[j]);
        j++;
    }
    return vec3;
}

class SET
{   
    public:
    vector<int> vec;

    SET() {}

    void Print()
    {   if(vec.size() == 0){cout<<endl;}
        else
        {   cout << vec[0];
            for(int i = 1; i<vec.size(); i++)
            {
                cout << "," << vec[i];
            
            }
            cout << endl;
        }

    }

    void Insert(int data)
    {
    if(vec.size() == 0){vec.push_back(data);}  

    else if (data>vec[vec.size()-1]){vec.push_back(data);}

    else
        {if(binarySearch(vec,data) == -1)
            {ins(vec,data);}
        }
    
    //return vec.size();
    }

    int Size() 
    {return vec.size();}

    int Delete(int data)
    {
        if(vec.size() != 0)
        {
            int a = binarySearch(vec , data);
            if(a != -1) {vec.erase(vec.begin() + a); return vec.size();}
            if(a == -1) {return vec.size();}


        }

        return vec.size();
    }

    int BelongsTo(int data)
    {
        if(vec.size() == 0){return 0;}
        else
        {
            int s = binarySearch(vec , data);
            if(s == -1){return 0;}
            else{return 1 ;}
        }
    }
    
    void Union(SET p)
    {   
        
        
        if(vec.size() == 0) {vec = p.vec;}
        else if (p.Size() != 0 and vec.size() !=0)
        {
            vec = merge(vec,p.vec);
        }
        

    }

    void Intersection(SET p)
    {
        vector <int> vec3;
        
        if(vec.size() == 0 or p.Size() == 0) {vec.clear();}
        else if (p.Size() != 0 and vec.size() !=0)
        {
            for(int i =0; i < vec.size(); i++)
            {if (p.BelongsTo(vec[i]) == 1)
            {
                vec3.push_back(vec[i]);
            }
            }
        }
        vec = vec3;
    }
    
    void Difference(SET p)
    {
        vector <int> vec3;
        if(p.Size() != 0 and vec.size() !=0)
        {
            for(int i = 0; i < vec.size(); i++)
            {
                if(p.BelongsTo(vec[i]) == 0 ){
                vec3.push_back(vec[i]);}

            }
        }
        vec = vec3;

    }

    void SymmetricDifferenec(SET p)
    {
        if(vec.size() == 0){vec = p.vec;}
        else if (p.Size() != 0 and vec.size() != 0)
        {
            
        
        
        SET q;
        q.vec = vec;
        SET r;
        r.vec = vec;

        q.Union(p);
        r.Intersection(p);

        q.Difference(r);

        vec = q.vec;
        
        }


    }
};

vector <SET> vecset;

void constr(int a)
{
    if((a == 0 and vecset.size() == 0)|| a > vecset.size() - 1)
    {
        SET* b = new SET();
        vecset.push_back(*b);
    } 

}


void driver_code(int a)
{
    
    int b;
    int c;

    
    if(a ==6 or a == 9 ) {cin >> b;}
    else{cin >> b >> c;}

    switch (a)
    {
    case(1):
        constr(b);
        vecset[b].Insert(c);
        cout << vecset[b].Size() << endl;
        break;
    
    case(2):
        if(b >= vecset.size()){cout << -1 << endl;}
        else{cout << vecset[b].Delete(c) << endl;}
        break;
    
    case(3):
        if(b >= vecset.size()){cout << -1 << endl;}
        else{cout << vecset[b].BelongsTo(c) << endl;}
        break;

    case(4):
        constr(b);
        constr(c);
        vecset[b].Union(vecset[c]);
        cout << vecset[b].Size() << endl;
        break;

    case(5):
        constr(b);
        constr(c);
        vecset[b].Intersection(vecset[c]);
        cout << vecset[b].Size() << endl;
        break;

    case(6):
        constr(b);
        cout << vecset[b].Size() << endl;
        break;

    case(7):
        constr(b);
        constr(c);
        vecset[b].Difference(vecset[c]);
        cout << vecset[b].Size() << endl;
        break;

    case(8):
        constr(b);
        constr(c);
        vecset[b].SymmetricDifferenec(vecset[c]);
        cout << vecset[b].Size() << endl;
        break;

    case(9):
        if(b >= vecset.size()){cout <<  endl;}
        else{vecset[b].Print();}
        break;



    
    default:
        case(-1):
            exit(0);
        break;
    }
}



int main(void)
{
    
    
   
    int a;
    while(cin >> a)
    {
        driver_code(a);
    }
}      