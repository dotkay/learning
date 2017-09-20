(* quicksort *)

(* partition a lst around a pivot element *)
let partition pivot lst =
  let rec aux (acc1, acc2) l =
    match l with
    | [] -> (acc1, acc2)
    | h::t -> 
      if (h < pivot) then aux (h::acc1, acc2) t
      else aux (acc1, h::acc2) t
  in
  aux ([], []) lst;;

(* quicksort using the partition function *)
let rec quicksort lst =
  match lst with
   | [] -> []
   | x::[] -> [x]
   | h::t -> let left, right = partition h t in
     quicksort left @ (h::quicksort right);;

