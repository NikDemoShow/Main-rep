#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
/*
struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;
	double b;
	double c;
};
*/
class FunctionPart {
private:
	char operation;
	double value;
public:
	FunctionPart(char new_op, double new_val) {
		operation = new_op;
		value = new_val;
	}
	double Apply(double val) const{
		if (operation == '+') {
			return val + value;
		}
		else if(operation == '-'){
			return val - value;
		}
		else if (operation == '*') {
			return val * value;
		}
		else {
			return val / value;
		}
	}
	void Invert() {
		if (operation == '+') {
			operation = '-';
		}
		else if (operation == '-') {
			operation = '+';
		}
		else if (operation == '*') {
			operation = '/';
		}
		else {
			operation = '*';
		}
	}
};


class Function {
public:
	void AddPart(char operation, double value) {
		parts.push_back({ operation, value });
	}
	double Apply(double value) const {
		for (const FunctionPart& part : parts) {
			value = part.Apply(value);
		}
		return value;
	}
	void Invert() {
		for (FunctionPart& part : parts) {
			part.Invert();
		}
		reverse(begin(parts), end(parts));
	}
private:
	vector<FunctionPart> parts;
};

/*
Function MakeWeightFunction(const Params& params,
	const Image& image) {
	Function function;
	function.AddPart('*', params.a);
	function.AddPart('-', image.freshness * params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
	const Image& image,
	double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}

int main() {
	Image image = { 10, 2, 6 };
	Params params = { 4, 2, 6 };
	cout << ComputeImageWeight(params, image) << endl;
	cout << ComputeQualityByWeight(params, image, 52) << endl;
	return 0;
}
*/