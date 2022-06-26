<<<<<<< HEAD
#pragma once
#include<vector>
#include<utility>
#include<deque>
#include<unordered_set>
#include<torch/script.h>
using std::pair;
using std::vector;
using std::deque;
using std::unordered_set;
class GomokuBoard
{
public:
	enum class PieceType:char {BLACK,WHITE,EMPTY};  //��������ռ�ÿռ�
	enum class BoardState {BLACK_WIN,WHITE_WIN,DRAW,NO_END};
	using Board = vector<vector<PieceType>>;
	using BoardData = vector<vector<vector<int>>>;
	GomokuBoard(unsigned int n=15, unsigned int n_in_row=5, unsigned int moveCacheNum=10);
	BoardState getBoardState();
	vector<unsigned int> getAvailableMove();
	void executeMove(unsigned int action);
	torch::Tensor getBoardData();   //��ȡ���̵���������
	BoardData getBoardData_py();    //��ȡ���̵��������� python�汾
	void display();
	void display_py();             //python�汾��display
private:
	const int NullSite = -1;
	unsigned int n;   //���̴�С
	unsigned int n_in_row;  //ʤ������
	PieceType curColor=PieceType::BLACK;   //��ǰ������ɫ
	unsigned int board_cnt = 0;    //������
	deque<int> moveCache;  //�����ֵ�����λ��
	vector<vector<PieceType>> board;
	inline void changeCurColor();
	inline PieceType anotherColor(PieceType color);
};

=======
version https://git-lfs.github.com/spec/v1
oid sha256:b397abf91020c3f57e926c5a2210f57003db632bf57c86f975cc74a5a704365f
size 1221
>>>>>>> 2673dac (pre)
