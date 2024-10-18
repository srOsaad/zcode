import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    width: 200
    height: 200
    color: "aqua"

    signal messageClicked(string message)

    function showMessage(message) {
        console.log("Showing message:", message)
        messageClicked(message)
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            showMessage("Hello, World!")
        }
    }

    Rectangle{
        width: 80
        height: 40
        color: ms.pressed ? "darkgray" : "gray"
        anchors.centerIn: parent

        MouseArea{
            id: ms
            anchors.fill: parent
        }
    }
}

