#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept> // For std::exception
#include "Simulation.h" // Include the header for Simulation class

using namespace std;

void batch_run() {
    cout << "Starting batch_run..." << endl; // Debugging statement
    vector<string> map_files = {
        "/workspaces/cobra/Instances/small/kiva-10-500-5.map",
        "/workspaces/cobra/Instances/small/kiva-20-500-5.map",
        "/workspaces/cobra/Instances/small/kiva-30-500-5.map",
        "/workspaces/cobra/Instances/small/kiva-40-500-5.map",
        "/workspaces/cobra/Instances/small/kiva-50-500-5.map"
    };

    string task_file = "/workspaces/cobra/Instances/small/kiva-5.task";
    ofstream output_file("consolidated_output.txt");
    if (!output_file.is_open()) {
        cerr << "Error opening output file!" << endl;
        return; // Exit if the file cannot be opened
    }

    for (const auto& map_file : map_files) {
        cout << "Running simulation for map: " << map_file << endl;
        cout << "Using task file: " << task_file << endl;
        try {
            Simulation simu(map_file, task_file);
            simu.run_TOTP(); // Using the specific run method

            // Call ShowTask() to display or log tasks
            simu.ShowTask(); // This will print to the console; you may capture it if needed.

            output_file << "Results for " << map_file << ":\n";
            output_file << "Simulation complete.\n"; // Add appropriate output information

        } catch (const std::exception& e) {
            cerr << "Exception occurred: " << e.what() << endl;
            output_file << "Exception occurred for " + map_file + ": " + e.what() + "\n";
        }
    }

    output_file.close();
    cout << "Batch run complete. Results consolidated in 'consolidated_output.txt'." << endl;
}

int main(int argc, char** argv) {
    // Your existing code here...
    // Example call to batch_run()
    batch_run();

    return 0;
}


	
