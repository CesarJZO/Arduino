/**
 * Abstract class to be the base for all circuits' configuration
 */
class Circuit {
protected:
	/**
	 * Run at the beginning of the program
	 */
	virtual void start();

	/**
	 * Run indefinitely while Arduino is on
	 */
	virtual void update();
};
