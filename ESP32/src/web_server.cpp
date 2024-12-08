#include "web_server.h"

WebServer server(80);

const char htmlPage[] = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RFID WebServer</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css">
    <style>
      h1 { text-align: center; padding-top: 40px; }
      h2 { padding-left: 10px; }
      .navigator { background-color: #0795df; overflow: hidden; border-bottom: 10px solid blue; max-height: 100px; height: 90px; }
    </style>
</head>
<body>
    <div class="navigator"></div>
    <h1>RFID Card Management</h1>
    <div class="container">
        <h2>Card Reading History</h2>
        <table class="table">
            <thead>
              <tr>
                <th scope="col">No.</th>
                <th scope="col">Card code</th>
                <th scope="col">Name</th>
                <th scope="col">Date</th>
                <th scope="col">Time</th>
                <th scope="col">Is member?</th>
              </tr>
            </thead>
            <tbody id="tableBody">
              <!-- Dữ liệu sẽ được cập nhật tại đây -->
            </tbody>
        </table>
    </div>

    <script>
        async function fetchTable() {
            try {
                const response = await fetch("/table");
                const tableContent = await response.text();
                document.getElementById("tableBody").innerHTML = tableContent;
            } catch (error) {
                console.error("Error fetching table data:", error);
            }
        }
        setInterval(fetchTable, 2000);
        fetchTable();
    </script>
</body>
</html>
)rawliteral";

void setupWebServer() {
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", htmlPage);
  });

  server.on("/table", HTTP_GET, []() {
    server.send(200, "text/plain", generateTable());
  });

  server.begin();
  Serial.println("Web server started");
}

void handleWebServer() {
  server.handleClient();
}

String generateTable() {
  String tableRows = "";
  for (int i = 0; i < scanCount; i++) {
    tableRows += "<tr>";
    tableRows += "<td>" + String(i + 1) + "</td>";
    tableRows += "<td>" + scanHistory[i].cardID + "</td>";
    tableRows += "<td>" + scanHistory[i].name + "</td>";
    tableRows += "<td>" + scanHistory[i].date + "</td>";
    tableRows += "<td>" + scanHistory[i].time + "</td>";
    tableRows += "<td>" + String(scanHistory[i].isMember ? "Yes" : "No") + "</td>";
    tableRows += "</tr>";
  }
  return tableRows;
}
