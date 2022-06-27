#pragma once
#include <torch/script.h>
#include<mutex>
#include <string>
#include <future>
#include <memory>
#include <queue>
#include <vector>
#include<utility>
#include"GomokuBoard.h"
using std::string;
using std::pair;
using std::vector;
using std::future;
using std::promise;
using std::unique_ptr;
using std::shared_ptr;
using std::mutex;
using std::condition_variable;
using std::queue;
using std::thread;
using torch::Tensor;
using torch::jit::script::Module;
class NeuralNet
{
public:
	using ActProbs_Value = pair<vector<double>, double>;
	NeuralNet(string model_path, bool use_gpu, unsigned int batch_size);
	future<ActProbs_Value> predict(GomokuBoard* gomoku);
	void setBatchSize(unsigned int batch_size) { this->batch_size = batch_size; };
	~NeuralNet();
private:
	using task_type = pair<Tensor, promise<ActProbs_Value>>;
	void infer();  // infer
	thread predictThread;  //�������Ԥ���߳�
	bool running=true;             //�߳���������
	queue<task_type> tasks;  //�߳������
	mutex lock;              //�߳���
	condition_variable cv;   //�������������
	Module module;
	unsigned int batch_size;
	bool use_gpu;
};

