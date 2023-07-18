import logo from './logo.svg';
import './App.css';
import { degrees, PDFDocument, rgb, StandardFonts } from 'pdf-lib';
import { saveAs } from 'file-saver';
import statePdf from "./pdfs/template.pdf"

async function modifyPdf() {
  const url = statePdf
  const existingPdfBytes = await fetch(url).then(res => res.arrayBuffer())
  // console  
  // const existingPdfBytes = fs.readFileSync(filePath);
  let X = 827;
  let Y = 1169;

  const pdfDoc = await PDFDocument.load(existingPdfBytes)
  const helveticaFont = await pdfDoc.embedFont(StandardFonts.Helvetica)

  const pages = pdfDoc.getPages()
  const firstPage = pages[0]
  const { width, height } = firstPage.getSize()
  console.log(width, height);
  firstPage.drawText('1898686', {
    x: 335,
    y: 730,
    size: 7,
    font: helveticaFont,
    color: rgb(1, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('2', {
    x: 730,
    y: 390,
    size: 7,
    font: helveticaFont,
    color: rgb(1, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('3', {
    x: 300,
    y: 837,
    size: 7,
    font: helveticaFont,
    color: rgb(1, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('4', {
    x: 550,
    y: 840,
    size: 7,
    font: helveticaFont,
    color: rgb(1, 0, 0),
    // rotate: degrees(-45),
  })
  // console.log("hello")
  const pdfBytes = await pdfDoc.save()

  const pdfBlob = new Blob([pdfBytes], { type: 'application/pdf' });

  // Save the PDF file using FileSaver.js
  saveAs(pdfBlob, 'myFile.pdf');

}

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <div>
          <button onClick={modifyPdf}>Click me!</button>
        </div>
      </header>
    </div>
  );
}

export default App;
