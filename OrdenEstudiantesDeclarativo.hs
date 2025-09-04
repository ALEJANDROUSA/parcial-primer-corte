import Data.List (sortBy)
import Data.Ord  (Down(..), comparing)

type Nombre = String
type Nota   = Double
type Est    = (Nombre, Nota)

orden :: Est -> Est -> Ordering
orden = comparing (Down . snd) <> comparing fst

ordenarEstudiantes :: [Est] -> [Est]
ordenarEstudiantes = sortBy orden

ejemplo :: [Est]
ejemplo =
  [ ("Ana",   4.5)
  , ("Luis",  5.0)
  , ("Lucia", 5.0)
  , ("Bruno", 3.8)
  , ("Ana",   5.0)
  ]

main :: IO ()
main = do
  putStrLn "Lista ordenada (nota desc, nombre asc en empate):"
  print (ordenarEstudiantes ejemplo)
