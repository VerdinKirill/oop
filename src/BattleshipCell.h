class BattleshipCell{
	public:
	BattleshipCell();
	int GetHpValue();
	void SetHpValue(int value);
	void AttackBattleshipCell();

	private:
	unsigned char hp;	
};