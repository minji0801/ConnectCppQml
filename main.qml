import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13
import "."

Window {
    property bool mbImageClicked: true
    property int mCount: 0

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function qmlSlotTestData(data) {    // slot으로 등록한 함수
        console.log("qmlSlotTestData data : " + data);
    }

    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: Item {
            id: element // 제일 첫화면을 설정하는 것으로 설정을 안하면 되돌아오기가 안된다.
            objectName: "mainscreen"    // 이전 화면에 대한 정보를 얻기 위해 설정하는 값

            Rectangle { // 배경 색을 지정하는 부분
                color: "red"
                anchors.fill: parent
            }

            Text {
                id: testData
                text: "main screen testData"
                font.bold: true
                font.pointSize: 30
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: testText
                text: "main screen"
                anchors.centerIn: parent
                font.bold: true
                font.pointSize: 50
            }

            Button {
                id: nextButton
                text: "go screen1"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: testText.bottom
                onClicked: {
                    console.log("push screen1")
                    stackView.push(Qt.resolvedUrl("qrc:/screen1.qml"))  // 다음 화면을 출력하기 위해 stack에 화면을 쌓는 코드
                }
            }

            Button {
                text: "go screen2"
                anchors.leftMargin: 30
                anchors.left: nextButton.right
                anchors.top: testText.bottom
                onClicked: {
                    console.log("push screen2")
                    stackView.push(Qt.resolvedUrl("qrc:/screen2.qml"))  // 다음 화면을 출력하기 위해 stack에 화면을 쌓는 코드
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:3;anchors_height:200;anchors_width:200}D{i:1;anchors_height:200;anchors_width:200}
}
##^##*/
