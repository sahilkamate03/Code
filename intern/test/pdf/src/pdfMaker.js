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
  const helveticaBoldFont = await pdfDoc.embedFont(StandardFonts.HelveticaBold)
  const helveticaFont = await pdfDoc.embedFont(StandardFonts.Helvetica)

  const pages = pdfDoc.getPages()
  const firstPage = pages[0]
  const { width, height } = firstPage.getSize()
  console.log(width, height);

  let zeroth_column = 245;
  let first_column = 330;
  let second_column = 410;
  let third_column = 490

  let dist = 13;
  let base = 728

  // -------------------- Section 0 (Header) Starts -------------------------------------
  base = 805;
  firstPage.drawText('A Y', {
    x: 46,
    y: base,
    size: 9,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })

  base = 790;
  firstPage.drawText('Name', {
    x: 50,
    y: base,
    size: 7,
    font: helveticaFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Emp Id', {
    x: 245,
    y: base,
    size: 7,
    font: helveticaFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Add', {
    x: 435,
    y: base,
    size: 7,
    font: helveticaFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })

  base = 778;
  firstPage.drawText('PAN', {
    x: 40,
    y: base,
    size: 7,
    font: helveticaFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('TAN', {
    x: 270,
    y: base,
    size: 7,
    font: helveticaFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  
  // -------------------- Section 0 (Header) Ends -------------------------------------


  // -------------------- Section 1 (Gross Salary) Starts -------------------------------------
  base =728;
  firstPage.drawText('Rs 1(a)', {
    x: first_column,
    y: base,
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 1(b)', {
    x: first_column,
    y: base - (dist * 1),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 1(c)', {
    x: first_column,
    y: base - (dist * 2),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 1(d)', {
    x: first_column,
    y: base - (dist * 3),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 1(e)', {
    x: second_column,
    y: base - (dist * 4),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  // -------------------- Section 1(Gross Salary) Ends -------------------------------------

  // -------------------- Section 2 (Less) Starts -------------------------------------
  base = 636;
  firstPage.drawText('Rs 2(a)', {
    x: zeroth_column,
    y: base,
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 2(b)', {
    x: zeroth_column,
    y: base - (dist * 1),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 2(c)', {
    x: zeroth_column,
    y: base - (dist * 2),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 2(d)', {
    x: second_column,
    y: base - (dist * 3),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  // -------------------- Section 2 (Less) Ends  -------------------------------------

  // -------------------- Section 3 (Balance) Starts -------------------------------------
  base = 584;
  firstPage.drawText('Rs 3', {
    x: second_column,
    y: base,
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  // -------------------- Section 3 (Balance) Ends -------------------------------------

  // -------------------- Section 4 (Deduction) Starts -------------------------------------
  base = 560;
  firstPage.drawText('Rs 4(a)', {
    x: first_column,
    y: base - (dist * 0),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 4(b)', {
    x: first_column,
    y: base - (dist * 1),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 4(c)', {
    x: first_column,
    y: base - (dist * 2),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  // -------------------- Section 4 (Deduction) Ends -------------------------------------

  // -------------------- Section 5 (Aggregate) Starts -------------------------------------
  base = 519;
  firstPage.drawText('Rs 5', {
    x: second_column,
    y: base,
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  // -------------------- Section 5 (Aggregate) Ends -------------------------------------

  // -------------------- Section 6 (Income Chargable) Starts -------------------------------------
  base = 505;
  firstPage.drawText('Rs 6', {
    x: third_column,
    y: base,
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  // -------------------- Section 6 (Income Chargable) Ends -------------------------------------

  // -------------------- Section 7 (Other Income) Starts -------------------------------------
  base = 442;
  firstPage.drawText('Rs 7', {
    x: second_column,
    y: base,
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  // -------------------- Section 7 (Other Income) Ends -------------------------------------

  // -------------------- Section 8 (Gross Total Income) Starts -------------------------------------
  base = 427;
  firstPage.drawText('Rs 8', {
    x: third_column,
    y: base,
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  // -------------------- Section 8 (Gross Total Income) Ends -------------------------------------

  // -------------------- Section 9 (Deduction under Chapter VIA) Starts -------------------------------------
  base = 390;

  // 9A
  firstPage.drawText('Rs 9Aa S', {
    x: second_column,
    y: base,
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Aa T', {
    x: third_column,
    y: base,
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Ab', {
    x: second_column,
    y: base - (dist * 1),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Ac', {
    x: second_column,
    y: base - (dist * 2),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })

  base = 337;
  // 9B First Column -------------
  firstPage.drawText('Rs 9Ba', {
    x: first_column,
    y: base - (dist * 0),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bb', {
    x: first_column,
    y: base - (dist * 1),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bc', {
    x: first_column,
    y: base - (dist * 2),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bc', {
    x: first_column,
    y: base - (dist * 3),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bd', {
    x: first_column,
    y: base - (dist * 4),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Be', {
    x: first_column,
    y: base - (dist * 5),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bf', {
    x: first_column,
    y: base - (dist * 6),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bg', {
    x: first_column,
    y: base - (dist * 7),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bh', {
    x: first_column,
    y: base - (dist * 8),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bi', {
    x: first_column,
    y: base - (dist * 9),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })


  // 9B Second Column -----------
  firstPage.drawText('Rs 9Ba', {
    x: second_column,
    y: base - (dist * 0),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bb', {
    x: second_column,
    y: base - (dist * 1),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bc', {
    x: second_column,
    y: base - (dist * 2),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bc', {
    x: second_column,
    y: base - (dist * 3),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bd', {
    x: second_column,
    y: base - (dist * 4),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Be', {
    x: second_column,
    y: base - (dist * 5),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bf', {
    x: second_column,
    y: base - (dist * 6),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bg', {
    x: second_column,
    y: base - (dist * 7),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bh', {
    x: second_column,
    y: base - (dist * 8),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bi', {
    x: second_column,
    y: base - (dist * 9),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })

  // 9B Third Column --------------
  firstPage.drawText('Rs 9Ba', {
    x: third_column,
    y: base - (dist * 0),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bb', {
    x: third_column,
    y: base - (dist * 1),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bc', {
    x: third_column,
    y: base - (dist * 2),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bc', {
    x: third_column,
    y: base - (dist * 3),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bd', {
    x: third_column,
    y: base - (dist * 4),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Be', {
    x: third_column,
    y: base - (dist * 5),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bf', {
    x: third_column,
    y: base - (dist * 6),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bg', {
    x: third_column,
    y: base - (dist * 7),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bh', {
    x: third_column,
    y: base - (dist * 8),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 9Bi', {
    x: third_column,
    y: base - (dist * 9),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })

  // -------------------- Section 9 (Deduction under Chapter VIA) Ends -------------------------------------

  // -------------------- Section 10 - 18 (Other) Starts -------------------------------------
  base = 205;
  firstPage.drawText('Rs 10', {
    x: third_column,
    y: base - (dist * 0),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 11', {
    x: third_column,
    y: base - (dist * 1),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 12', {
    x: third_column,
    y: base - (dist * 2),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 12a', {
    x: third_column,
    y: base - (dist * 3),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 13', {
    x: third_column,
    y: base - (dist * 4),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 14', {
    x: third_column,
    y: base - (dist * 5),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 15', {
    x: third_column,
    y: base - (dist * 6),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 16', {
    x: third_column,
    y: base - (dist * 7),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 17', {
    x: second_column,
    y: base - (dist * 8),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 17a', {
    x: second_column,
    y: base - (dist * 9),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  firstPage.drawText('Rs 18', {
    x: third_column,
    y: base - (dist * 10),
    size: 7,
    font: helveticaBoldFont,
    color: rgb(0, 0, 0),
    // rotate: degrees(-45),
  })
  // -------------------- Section 10 - 18 (Other) Ends -------------------------------------

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
