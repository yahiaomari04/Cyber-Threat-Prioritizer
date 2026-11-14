// Cyber Threat Prioritizer - Heap Sort 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>
#include <limits>

using namespace std;

struct Threat
{
    int id;
    string attackType;
    string severity;
    double cvss;
    double riskScore;
};

int getSeverityWeight(const string& sev)
{
    string s;
    for (char c : sev) s += toupper(static_cast<unsigned char>(c));
    if (s == "LOW") return 1;
    if (s == "MEDIUM") return 2;
    if (s == "HIGH") return 3;
    if (s == "CRITICAL") return 4;
    return 0;
}

double calculateRiskScore(double cvss, int weight)
{
    return cvss * weight;
}

void heapify(vector<Threat>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].riskScore > arr[largest].riskScore)
        largest = left;

    if (right < n && arr[right].riskScore > arr[largest].riskScore)
        largest = right;

    if (largest != i)
    {
        Threat temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(vector<Threat>& arr)
{
    int n = static_cast<int>(arr.size());

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 1; --i)
    {
        Threat temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

    
    for (int i = 0, j = n - 1; i < j; ++i, --j)
    {
        Threat tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void displayThreats(const vector<Threat>& arr)
{
    cout << fixed << setprecision(1);
    for (size_t i = 0; i < arr.size(); ++i)
    {
        const Threat& t = arr[i];
        cout << "Alert ID: " << t.id << " | ";
        cout << "Attack: " << t.attackType << " | ";
        cout << "Severity: " << t.severity << " | ";
        cout << "CVSS: " << t.cvss << " | ";
        cout << "Risk: " << t.riskScore << "\n";
    }
}

int main()
{
    cout << "========================================\n";
    cout << "       CYBER THREAT PRIORITIZER\n";
    cout << "========================================\n\n";

    int n = 0;
    cout << "Enter number of alerts: ";
    while (!(cin >> n) || n <= 0)
    {
        cout << "Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Threat> alerts;
    alerts.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        Threat t;
        cout << "\nAlert " << (i + 1) << "\n";
        cout << "Alert ID: ";
        while (!(cin >> t.id))
        {
            cout << "Enter a valid integer for Alert ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Attack Type: ";
        getline(cin, t.attackType);

        string sev;
        while (true)
        {
            cout << "Severity (Low, Medium, High, Critical): ";
            getline(cin, sev);
            int w = getSeverityWeight(sev);
            if (w > 0)
            {
                t.severity = sev;
                break;
            }
            cout << "Invalid severity. Please type Low, Medium, High, or Critical.\n";
        }

        cout << "CVSS Score: ";
        while (!(cin >> t.cvss && t.cvss >= 0.0 && t.cvss <= 10.0))
        {
            cout << "Enter a valid number for CVSS Score: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int weight = getSeverityWeight(t.severity);
        t.riskScore = calculateRiskScore(t.cvss, weight);

        alerts.push_back(t);
    }

    cout << "\n--- Alerts before sorting ---\n";
    displayThreats(alerts);

    heapSort(alerts);

    cout << "\n--- Alerts after Heap Sort (highest -> lowest) ---\n";
    displayThreats(alerts);

    cout << "\n========== PRIORITY ORDER ==========\n";
    cout << left << setw(6) << "Rank" << setw(10) << "Alert" << setw(20) << "Attack Type" << setw(12) << "Severity" << setw(8) << "CVSS" << setw(10) << "Risk" << "\n";
    cout << "-----------------------------------------------\n";
    cout << fixed << setprecision(1);
    for (size_t i = 0; i < alerts.size(); ++i)
    {
        const Threat& t = alerts[i];
        cout << left << setw(6) << (i + 1)
             << setw(10) << t.id
             << setw(20) << t.attackType
             << setw(12) << t.severity
             << setw(8) << t.cvss
             << setw(10) << t.riskScore << "\n";
    }

    if (!alerts.empty())
    {
        const Threat& top = alerts[0];
        cout << "\n========================================\n";
        cout << "          HIGHEST PRIORITY\n";
        cout << "========================================\n";
        cout << "Alert ID: " << top.id << "\n";
        cout << "Attack Type: " << top.attackType << "\n";
        cout << "Severity: " << top.severity << "\n";
        cout << fixed << setprecision(1);
        cout << "CVSS Score: " << top.cvss << "\n";
        cout << "Risk Score: " << top.riskScore << "\n";
    }

    cout << "\nHeap Sort Time Complexity: O(n log n)\n";
    cout << "Additional Space Complexity: O(1)\n";

    return 0;
}
