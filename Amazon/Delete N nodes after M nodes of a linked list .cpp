class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {
        //Add code here   
    
        while(head){
            // Node* temp = head;
            int mm = m;
            int nn = n;
            while(head && --mm){
                head = head->next;
            }
            Node* temp = head;
            while(head && nn--){
                head = head->next;
            }
            if(temp){
            head = head?head->next : nullptr;
                temp->next = head;
            }
            
        }

    }
};
