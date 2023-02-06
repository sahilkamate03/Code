import './App.css';
import Header from './components/header'
import Todos from './components/todos'
import Footer from './components/footer'

function App() {

  let todos = [
    {
      'sno': 1,
      'title': 'Go for picnic',
      'desc': 'Time Pass'
    },
    {
      'sno': 2,
      'title': 'Go for Tour',
      'desc': 'Time Pass'
    },
    {
      'sno': 3,
      'title': 'Go for Study',
      'desc': 'Time Pass'
    }
  ]

  return (
    <>
      <Header title="DayPlanners" searchBar={true} />
      <Todos todos = {todos}/>
      <Footer />
    </>
  );
}

export default App;
