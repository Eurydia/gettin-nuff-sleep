// input time went to sleep
// input time woke up
// input age
//calculate sleep hours

//suggestion based on sleep hours and age

// input time to wake up
// or input hours to alarm from now on

//setup alarm clock
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class User {
	private:

		//inputs
		int age;

		int hour_to_bed;
		int min_to_bed;

		int hour_off_bed;
		int min_off_bed;

		//calcuate for
		int total_sleep_min;


		//calculating functions >> calculate
		int calculate_time_to_bed() {
			int to_bed = (hour_to_bed * 100) + min_to_bed;
			return to_bed;
		}

		int calculate_time_off_bed() {
			int off_bed = (hour_off_bed * 100) + min_off_bed;
			return off_bed;
		}

		void calculate_total_sleep_min() {
			if (calculate_time_to_bed() > calculate_time_off_bed()) {
				total_sleep_min = (1440 - ((hour_to_bed * 60) + min_to_bed)) + ((hour_off_bed * 60)+ min_off_bed);
			}
			else {
				total_sleep_min = ((hour_off_bed * 60) + min_off_bed) - ((hour_to_bed * 60) + min_to_bed);
			}
		}


	public:

		//initializing functions >> set
		void set_hour_to_bed(int a) {
			hour_to_bed = a;
		}

		void set_min_to_bed(int b) {
			min_to_bed = b;
		}

		void set_hour_off_bed(int any) {
			hour_off_bed = any;
		}

		void set_min_off_bed(int any) {
			min_off_bed = any;
		}

		void set_age(int any) {
			age = any;
		}

		//returning functions >> get

		void get_sleep_quality() {
			const int c[7][2] = {540,720,480,600,420,600,420,720,540,720,600,720,660,720};
			int age_class = age / 10;

			calculate_total_sleep_min();
			int sleep_hour = total_sleep_min / 60;
			int sleep_min = total_sleep_min % 60;

			if (age_class > 6) {
				age_class = 6;
			}

			cout << "\n#\tFor someone at the age of " << age << "." << endl;
			cout << "\n#\tYou should be getting between " << c[age_class][0] / 60 << " and " << c[age_class][1] / 60 << " hours of sleep." << endl;

			if (total_sleep_min > c[age_class][1]) {
				cout << "\n#\tYour sleep duration of " << sleep_hour << " hour(s) and " << sleep_min << " minute(s) is a bit too much!" << endl;
				cout << "\n#\tPlease, trim it down a bit." << endl;
			}

			else if (total_sleep_min < c[age_class][0]) {
				cout << "\n#\tYour sleep duration of " << sleep_hour << " hour(s) and " << sleep_min << " minute(s) is too little!" << endl;
				cout << "\n#\tPlease, get more rest." << endl;	
			}
			
			else {
				cout << "\n#\tYour sleep duration of " << sleep_hour << " hour(s) and " << sleep_min << " minute(s) is perfect." << endl;
				cout << "\n#\tKeep it up!" << endl;	
			}
		}
		
};

void input_error() {
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "\n#\tThere seems to be and error in your input" << endl;
	cout << "\n#\tMind trying again?" << endl;
}

int main() {
	User user;

	int a;

		cout << "\n#\tHello! How may I be of service?" << endl;

		cout << "\n\t\tDo you think I'm getting enough sleep?" << endl;
		
		cout << "\n#\tWell, of course!" << endl;
		cout << "\n#\tBut, I need you to answer some questions." << endl;

		cout << "\n#\t(1/5)" << endl;

		while (true) {
			cout << "\n#\tWhat hour do you normally go to bed?" << endl;
			cout << "\n\tI usually go to bed around (0 - 23) >> ";

			cin >> a;

			if (!cin.fail() && a <= 23 && a >= 0) {
				user.set_hour_to_bed(a);
				break;
			}
			else {
				input_error();
			}
		}

		cout << "\n#\t(2/5)" << endl;

		while (true) {
			cout << "\n#\tWhat minute do you normally go to bed?" << endl;
			cout << "\n\tI usually go to bed around (0 - 59) >> ";

			cin >> a;

			if (!cin.fail() && a <= 59 && a >= 0) {
				user.set_min_to_bed(a);
				break;
			}
			else {
				input_error();
			}
		}

		cout << "\n#\t(3/5)" << endl;

		while (true) {
			cout << "\n#\tWhat hour do you normally get out of bed?" << endl;
			cout << "\n\tI usually wake up around (00 - 23) >> ";

			cin >> a;

			if (!cin.fail() && a <= 23 && a >= 0) {
				user.set_hour_off_bed(a);
				break;
			}
			else {
				input_error();
			}
		}

		cout << "\n#\t(4/5)" << endl;

		while (true) {
			cout << "\n#\tWhat minute do you normally get out of bed?" << endl;
			cout << "\n\tI usually wake up around (0 - 59) >> ";

			cin >> a;

			if (!cin.fail() && a <= 59 && a >= 0) {
				user.set_min_off_bed(a);
				break;
			}
			else {
				input_error();
			}
		}

		cout << "\n#\t(5/5)" << endl;

		while (true) {
			cout << "\n#\tHow old are you again?" << endl;
			cout << "\n\tI'm >> ";

			cin >> a;

			if (!cin.fail() && a >= 0) {
				user.set_age(a);
				break;
			}
			else {
				input_error();
			}
		}
		
		user.get_sleep_quality();
}