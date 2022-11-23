#include<iostream>
using namespace std;
struct SinhVien {
	string ten, mssv, lop, ngaysinh,gioitinh;
	double gpa;
	int ngay, thang, nam;
};
struct SV {
	SinhVien s;
	SV* next;
};
typedef struct SV* sv;
sv makeNode() {
	SinhVien s;
	int ngay, thang, nam;
	cout << "Nhap thong tin sinh vien:\n";
	cout << "Nhap MSSV:";
	cin >> s.mssv;
	cout << "Nhap ten:";
	cin.ignore();
	getline(cin, s.ten);
	cout<<"Nhap lop:";
	cin>>s.lop;
	do{
	cout<<"Nhap gioi tinh:";
	cin>>s.gioitinh;
	}
	while (s.gioitinh!="nam"&&s.gioitinh!="nu");
	do{
	cout << "Nhap ngay :";
	cin >> s.ngay;}
	while (s.ngay <1 || s.ngay >31);
	do {
	    cout << "Nhap thang :";
	cin >> s.thang;
	}
	while (s.thang <1 || s.thang >12);
	do {
	    cout << "Nhap nam :";
	cin >> s.nam;
	}
	while (s.nam<1997||s.nam>2003);
	do{
	    cout<<"Nhap GPA:";
	cin>>s.gpa;
	}
	while(s.gpa<1 || s.gpa>4);
	sv p = new SV();
	p->s = s;
	p->next = NULL;
	return p;
}
bool empty(sv head) {
	return head == NULL;
}
int Size(sv head) {
	int dem = 0;
	while (head != NULL) {
		++dem;
		head = head->next;
	}
	return dem;
}
void addFirst(sv &head) {
	sv newNode = makeNode();
	newNode->next = head;
	head = newNode;
}
void addLast(sv &head){
	sv tmp = head;
		sv newNode = makeNode();
		if(head == NULL){
			head = newNode;
			return;
		}
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = newNode;
}
void insertMiddle(sv &head, int pos){
	int n = Size(head);
	if(pos <= 0 || pos > n+1){
		cout<<"Vi tri chen khong hon le!\n";
		return;
	}if(pos == 1){
		addFirst(head);
		return;
	}
	sv tmp = head;
	for (int i=1;i <= pos-2;i++){
		tmp = tmp->next;
	}
	sv newNode = makeNode();
	newNode->next = tmp->next;
	tmp->next = newNode;
}
void deleteFirst(sv &head){
	if(head == NULL) return;
	sv tmp = head;
	head = head->next;
	delete tmp;
}
void deleteLast(sv &head){
	if(head == NULL){
		return;
	}
	sv tmp = head;
	if(tmp->next == NULL){
		head = NULL;
		delete tmp;
		return;
	}
	while (tmp->next->next!=NULL){
		tmp = tmp->next;
	}
	sv last = tmp->next;
	tmp->next = NULL;
	delete last;
}
void deleteMiddle(sv &head,int pos){
	int n = Size(head);
	if(pos < 1 || pos > n ) 
	return;
	if(pos == 1)
	deleteFirst(head);
	else{
		sv tmp = head;
		for (int i = 1;i<= pos-2;i++){
			tmp = tmp->next;
		}
		sv kth = tmp->next;
	tmp->next = kth->next;
	delete kth;
}
}
void in(SinhVien s){
	cout<<"---------THONG TIN SINH VIEN-----------\n";
    cout<<"MSSV:"<<s.mssv<<endl;
	cout<<"Ho Ten:"<<s.ten<<endl;
	cout<<"lop:"<<s.lop<<endl;
	cout<<"Gioi tinh:"<<s.gioitinh<<endl;
	cout<<"Ngay sinh:"<<s.ngay<<"/"<<s.thang<<"/"<<s.nam;
	cout<<"GPA:"<<s.gpa<<endl;
	cout<<"---------------------------------------\n";
}
void inds(sv head){
	cout<<"Danh sach sinh vien:\n";
	while (head!=NULL){
		in(head->s);
		head = head->next;
	}
	cout<<endl;
}
void sapxep(sv &head){
	for (sv i = head; i!=NULL;i = i->next){
		sv minsv = i;
		for (sv j = i->next;j != NULL;j = j->next){
			if (minsv->s.gpa > j->s.gpa){
				minsv = j;
			}
			else if(minsv->s.gpa == j->s.gpa){
				if(minsv->s.ten >j->s.ten){
					minsv = j;
				}
			}
		}
		SinhVien tmp = minsv->s;
		minsv->s = i->s;
		i->s = tmp;
	}
}
void timkiemtheomssv(sv head){
	string x;
	cout<<"Nhap MSSV can tim:";
	cin.ignore();
	getline(cin,x);
	while (head !=NULL){
		if (head->s.mssv == x){
			cout<<"Da tim thay sinh vien\n";
			in(head->s);
			return;
		}
		head = head->next;
	}
	cout<<"Khong tim thay sinh vien!\n";
	return ;
}
int main(){
	sv head = NULL;
	while(1){
		cout<<"----------------MENU------------------\n";
		cout<<"1.Chen sinh vien vao dau danh sach\n";
		cout<<"2.Chen sinh vien vao cuoi danh sach\n";
		cout<<"3.Chen sinh vien bat ky\n";
		cout<<"4.xoa sinh vien khoi dau danh sach\n";
		cout<<"5.Xoa sinh vien khoi cuoi danh sach\n";
		cout<<"6.xoa sinh vien giua danh sach\n";
		cout<<"7.Sap xep sinh vien theo diem GPA tang dan\n";
		cout<<"8.Tim sinh vien theo MSSV\n";
		cout<<"9.Duyet danh sach\n";
		cout<<"0.Thoat\n";
		cout<<"-------------------------------------\n";
		cout<<"Nhap lua chon:";
		int lc;cin>>lc;
		if ( lc==1){
			addFirst(head);
		}
		else if(lc==2){
			addLast(head);
		}
		else if (lc==3){
			int pos;
			cout<<"Nhap vi tri can chen:";
			cin>>pos;
			insertMiddle(head, pos);
		}else if(lc==4){
			deleteFirst(head);
		}else if(lc==5){
			deleteLast(head);
		}else if (lc==6){
			int pos;
			cout<<"Nhap vi tri can xoa:";
			cin>>pos;
			deleteMiddle(head,pos);
		}
		else if(lc == 7){
			sapxep(head);
		}
		else if(lc == 8){
			timkiemtheomssv(head);
		}
		else if(lc == 9){
			inds(head);
		}
		else if(lc == 0){
			break;
		}
	}
}
