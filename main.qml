import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13
import ConnectEvent 1.0 // connectevent.cpp 파일의 등록된 클래스를 import 시켜준다. (cpp에서 1,0으로 등록하였기 때문에 import시에 1.0으로 적어준것!)
import CountNumber 1.0  // 20200703 새로 추가한 부분
import "."


Window {
    property bool mbImageClicked: true
    property int mCount: 0

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal qmlSignalStringData(var stringData); // qml에서 signal을 선언해주는 부분
    signal qmlSignalintData(var intData);       // qml에서 signal을 선언해주는 부분

    function qmlSlotTestData(data) {    // slot으로 등록한 함수
        console.log("qmlSlotTestData data : " + data);
    }

    ConnectEvent    // qml에서 클래스를 사용할 수 있도록 qml형식으로 선언해준다.
    {
        id: connectEvent;   // 클래스를 선언해주고 id를 등록
    }

    // 20200703 새로 추가한 부분
    CountNumber
    {
        id: countNumber;
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

                // 20200703 새로 추가한 부분
                Rectangle {
                    id: countRectangle
                    x: 8
                    y: 328
                    width: 200
                    height: 144
                    color: "#ffffff"

                    Button {
                        id: plusButton
                        x: 32
                        y: 21
                        width: 40
                        height: 40
                        text: qsTr("+")
                        font.pointSize: 20
                        font.bold: true

                        onClicked:
                        {
                            // + 함수 실행 -> count up
                            // 클래스에 정의된 함수 가져와 실행
                            number.text = countNumber.countUp(number.text);
                        }
                    }

                    Button {
                        id: minusButton
                        x: 127
                        y: 21
                        width: 40
                        height: 40
                        text: qsTr("-")
                        font.bold: true
                        font.pointSize: 20

                        onClicked:
                        {
                            // - 함수 실행 -> count down
                            // 클래스에 정의된 함수 가져와 실행
                            number.text = countNumber.countDown(number.text);
                        }
                    }

                    Text {
                        id: number
                        x: 60
                        y: 93
                        width: 80
                        height: 31
                        text: qsTr("0")
                        font.bold: true
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: 30
                    }
                }
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

            /*
            Button {
                id: intButton   // int형 데이터를 매개변수에 넣어서 cpp함수를 호출하는 버튼
                text: "int data"
                anchors.right: strButton.left
                anchors.rightMargin: 30
                anchors.top: testText.bottom
                onClicked: {
                    console.log("qml signal intButton click")
                    qmlSignalintData(1000);  // qml에서 signal을 발생시키는 부분
                }
            }
            */

            Button {
                id: strButton   // string형 데이터를 매개변수에 넣어서 cpp함수를 호출하는 버튼
                text: "String Data"
                anchors.right: nextButton.left
                anchors.rightMargin: 30
                anchors.top: testText.bottom
                onClicked: {
                    console.log("qml signal strButton click")
                    //qmlSignalStringData("this is qml signal data");  // qml에서 signal을 발생시키는 부분
                    connectEvent.cppStringTestMethod("qml register class method");  // 등록한 클래스의 함수를 호출하는 방법
                }
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
    D{i:1;anchors_height:200;anchors_width:200}D{i:3;anchors_height:200;anchors_width:200}
}
##^##*/
