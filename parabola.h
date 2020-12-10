class Parabola
{
	private:
		float a, b, c;

	public:
		Parabola();
		Parabola(float a, float b, float c);

		float getA();
		float getB();
		float getC();
		void WidParab();
		void PrintParab();
		void PrintTopParab();
		bool IsPointIn(float x, float y);
		void PrintPointLine(float a_p, float b_p);
		void PrintPointParabola(Parabola* p);
		float SquareParabola(Parabola* p);
};