class GameObject {
	private:
		int x, y;
		int w_mask, h_mask;

	public:
		virtual GameObject();

		//Custom:
		virtual void start()  = 0;
		virtual void update() = 0;
		virtual void dead()   = 0;

		virtual void addDamage(int val) = 0;

		virtual bool isTarget() = 0;
		virtual bool isSolid()  = 0;

		virtual void draw() = 0;

		virtual ~GameObject();

		//Native:
		int getX();
		int getY();
		void setPosition(int x, int y);

		int maskWidth();
		int heightMask();
}