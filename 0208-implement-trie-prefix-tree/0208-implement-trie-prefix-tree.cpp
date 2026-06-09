struct Node{
     Node* links[26] = {nullptr};

     bool flag = false;

     bool contains(char ch){
        return links[ch-'a']!=nullptr;
     }
   
     void put(char ch,Node* node)
     {
        links[ch-'a'] = node;
     }

     Node* get(char ch)
     {
        return links[ch-'a'];
     }

     void setEnd(){
        flag = true;
     }

    bool isEnd()
    {
        return flag;
    }



};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* tmp = root;
        for(auto ch : word)
        {
            if(!tmp->contains(ch))
            {
               tmp -> put(ch,new Node());
            }
            tmp = tmp->get(ch);
        }
        tmp->setEnd();
    }

    
    bool search(string word) {
        Node* tmp = root;
        for(auto it : word)
        {
            if(!tmp->contains(it))
            {
                return false;
            }
            tmp = tmp->get(it);
        }
        return tmp->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* tmp = root;
        for(auto it : prefix)
        {
            if(!tmp->contains(it))return false;
            tmp = tmp->get(it);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */