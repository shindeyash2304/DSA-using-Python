class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node* head1P = head1;
        Node* head2P = head2;
        
        while(head1P != head2P){
            head1P = head1P == NULL ? head2:head1P->next;
            head2P = head2P == NULL ? head1:head2P->next;
        }
        return head1P;
    }
};